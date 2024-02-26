// Fill out your copyright notice in the Description page of Project Settings.


#include "Portal.h"

#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "IDGJ3/Subsystems/PortalsManagerSubsystem.h"
#include "IDGJ3/Utils/CustomUtils.h"

// Sets default values
APortal::APortal()
{
	PrimaryActorTick.bCanEverTick = false;

	Pivot = CreateDefaultSubobject<USceneComponent>(TEXT("Pivot"));
	RootComponent = Pivot;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	BoxComponent->SetupAttachment(Pivot);
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Physical Body"));
	StaticMesh->SetupAttachment(Pivot);
	
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Pivot);
}

bool APortal::GetIsActive()
{
	return bIsActive;
}

void APortal::SetIsActive(bool IsActive)
{
	bIsActive = IsActive;
}

EPortalType APortal::GetPortalType()
{
	return PortalType;
}

void APortal::ActivatePortal(EPortalType PortalTyp)
{
	PortalType = PortalTyp;

	if (UPortalsManagerSubsystem* PortalsManager = GetWorld()->GetSubsystem<UPortalsManagerSubsystem>())
	{
		PortalsManager->SetPortal(PortalType, this);
	}
	OnPortalActivated.Broadcast();
	SetIsActive(true);
	
}

void APortal::DeactivatePortal(EPortalType PortalTyp)
{
	PortalType = EPortalType::Null;
	if (UPortalsManagerSubsystem* PortalsManager = GetWorld()->GetSubsystem<UPortalsManagerSubsystem>())
	{
		PortalsManager->SetPortal(PortalTyp, nullptr);
	}
	OnPortalDeactivated.Broadcast();
	SetIsActive(false);

}

void APortal::BeginPlay()
{
	Super::BeginPlay();
}



