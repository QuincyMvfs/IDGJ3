// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "IDGJ3Character.generated.h"

enum class EPortalType : uint8;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRedShoot, const FHitResult&, HitResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGreenShoot, const FHitResult&, HitResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRedPortalPressed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGreenPortalPressed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPauseTV);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayTV);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSetTVFail);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPause);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUnPause);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPauseFailed);

class UShootingComponent;
UCLASS(config=Game)
class AIDGJ3Character : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* HandsSkeletalMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* RemoteStaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* RemoteMesh;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	// Shoot green ray for portal (left click)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* GreenPortal;

	// Shoot green ray for portal (right click)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* RedPortal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* PauseObject;

public:
	UPROPERTY(BlueprintAssignable)
	FOnPause OnPauseEvent;

	UPROPERTY(BlueprintAssignable)
	FOnUnPause OnUnPauseEvent;

	UPROPERTY(BlueprintAssignable)
	FOnPauseFailed OnPauseFailedEvent;

	UPROPERTY(BlueprintAssignable)
	FOnPlayTV OnPlayTVEvent;

	UPROPERTY(BlueprintAssignable)
	FOnPauseTV OnPauseTVEvent;

	UPROPERTY(BlueprintAssignable)
	FOnSetTVFail OnSetTVFailEvent;

	UPROPERTY(BlueprintAssignable)
	FOnRedPortalPressed OnRedPortalPressedEvent;

	UPROPERTY(BlueprintAssignable)
	FOnGreenPortalPressed OnGreenPortalPressedEvent;
	
	UPROPERTY(BlueprintAssignable)
	FOnGreenShoot OnGreenShoot;

	UPROPERTY(BlueprintAssignable)
	FOnRedShoot OnRedShoot;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UShootingComponent* ShootingComponent;

public:
	AIDGJ3Character();
	

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	UFUNCTION()
	void ShootGreenPortal();

	UFUNCTION()
	void ShootRedPortal();

	UFUNCTION()
	void ShootingPortal(EPortalType PortalType);

	UFUNCTION()
	void Pause();
	
protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};



