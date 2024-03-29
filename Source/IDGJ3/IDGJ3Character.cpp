// Copyright Epic Games, Inc. All Rights Reserved.

#include "IDGJ3Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Actors/Portal.h"
#include "Components/PausedData.h"
#include "Components/ShootingComponent.h"
#include "Interfaces/Activatable.h"
#include "Interfaces/Pausable.h" 
#include "Subsystems/PortalsManagerSubsystem.h"
#include "Utils/CustomUtils.h"


//////////////////////////////////////////////////////////////////////////
// AIDGJ3Character

AIDGJ3Character::AIDGJ3Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	HandsSkeletalMesh = GetMesh();
	HandsSkeletalMesh->SetupAttachment(FollowCamera);
	RemoteStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Remote"));
	RemoteStaticMesh->SetupAttachment(HandsSkeletalMesh, "RightHand");

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

	ShootingComponent = CreateDefaultSubobject<UShootingComponent>(TEXT("ShootingComponent"));
}

void AIDGJ3Character::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// Input



void AIDGJ3Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AIDGJ3Character::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AIDGJ3Character::Look);

		//Shooting
		EnhancedInputComponent->BindAction(GreenPortal, ETriggerEvent::Completed, this, &AIDGJ3Character::ShootGreenPortal);
		EnhancedInputComponent->BindAction(RedPortal, ETriggerEvent::Completed, this, &AIDGJ3Character::ShootRedPortal);
		EnhancedInputComponent->BindAction(PauseObject, ETriggerEvent::Completed, this, &AIDGJ3Character::Pause);
		
	}

}

void AIDGJ3Character::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AIDGJ3Character::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AIDGJ3Character::ShootRedPortal()
{
	ShootingPortal(EPortalType::Red);
	OnRedPortalPressedEvent.Broadcast();
}

void AIDGJ3Character::ShootGreenPortal()
{
	ShootingPortal(EPortalType::Green);
	OnGreenPortalPressedEvent.Broadcast();
}


void AIDGJ3Character::ShootingPortal(EPortalType PortalType)
{
	UWorld* World = GetWorld();
	if(!IsValid(World)) return;
	FHitResult Hit = ShootingComponent->Shoot(FollowCamera->GetComponentLocation(), FollowCamera->GetForwardVector(), FColor::Cyan);

	UPortalsManagerSubsystem* PortalsManager = World->GetSubsystem<UPortalsManagerSubsystem>();
	if (!IsValid(PortalsManager)) return;
	
	APortal* Portal = Cast<APortal>(Hit.GetActor());
	if(!IsValid(Portal))
	{
		OnSetTVFailEvent.Broadcast();
		return;
	}
		
	if(Portal->GetIsActive() && Portal->GetPortalType() == PortalType)
	{
		Portal->DeactivatePortal(PortalType);
		OnPauseTVEvent.Broadcast();
	}
	else if(Portal->GetIsActive() && Portal->GetPortalType() != PortalType)
	{
		if(PortalsManager->GetPortalsMap()[PortalType])
		{
			PortalsManager->GetPortalsMap()[PortalType]->DeactivatePortal(PortalType);
		}
		Portal->DeactivatePortal(Portal->GetPortalType());
		Portal->ActivatePortal(PortalType);
		OnPlayTVEvent.Broadcast();
	}
	else if(!Portal->GetIsActive())
	{
		if(PortalsManager->GetPortalsMap()[PortalType])
		{
			PortalsManager->GetPortalsMap()[PortalType]->DeactivatePortal(PortalType);
		}
		Portal->ActivatePortal(PortalType);
		OnPlayTVEvent.Broadcast();
	}
}

void AIDGJ3Character::Pause()
{
	FHitResult Hit = ShootingComponent->Shoot(FollowCamera->GetComponentLocation(), FollowCamera->GetForwardVector(), FColor::Cyan);
	
	if (AActor* HitActor = Hit.GetActor())
	{
		if (HitActor->GetClass()->ImplementsInterface(UPausable::StaticClass()))
		{
			IPausable::Execute_TogglePause(Hit.GetActor());
			if (const UPausedData* PauseData = HitActor->GetComponentByClass<UPausedData>())
			{
				if (PauseData->IsPaused) { OnPauseEvent.Broadcast(); }
				else { OnUnPauseEvent.Broadcast(); }
			}
		}
		else { OnPauseFailedEvent.Broadcast(); }
	}
	else { OnPauseFailedEvent.Broadcast(); }
}
