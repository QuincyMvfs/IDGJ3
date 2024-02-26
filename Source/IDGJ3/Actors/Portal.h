// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IDGJ3/Interfaces/Activatable.h"
#include "Portal.generated.h"

enum class EPortalType : uint8;
class UBoxComponent;
class UArrowComponent;
class UStaticMeshComponent;
class USceneComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPortalActivated);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPortalDeactivated);

UCLASS()
class IDGJ3_API APortal : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintAssignable)
	FOnPortalActivated OnPortalActivated;

	UPROPERTY(BlueprintAssignable)
	FOnPortalDeactivated OnPortalDeactivated;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	USceneComponent* Pivot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* BoxComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UArrowComponent* Arrow;

	UPROPERTY(BlueprintReadOnly, Category = "PortalType")
	EPortalType PortalType;

	UPROPERTY(BlueprintReadOnly)
	uint8 bIsActive : 1;

protected:
	virtual void BeginPlay() override;

public:	
	APortal();

	UFUNCTION(BlueprintPure)
	bool GetIsActive();

	UFUNCTION(BlueprintCallable)
	void SetIsActive(bool IsActive);

	UFUNCTION(BlueprintPure)
	EPortalType GetPortalType();

	UFUNCTION()
	void ActivatePortal(EPortalType PortalTyp);

	UFUNCTION()
	void DeactivatePortal(EPortalType PortalTyp);
	
};
