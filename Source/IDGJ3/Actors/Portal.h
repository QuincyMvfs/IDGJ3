// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IDGJ3/Interfaces/Activatable.h"
#include "Portal.generated.h"

class UBoxComponent;
class UArrowComponent;
class UStaticMeshComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPortalActivated);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPortalDeactivated);

UCLASS()
class IDGJ3_API APortal : public AActor, public IActivatable
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintAssignable)
	FOnPortalActivated OnPortalActivated;

	UPROPERTY(BlueprintAssignable)
	FOnPortalDeactivated OnPortalDeactivated;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UBoxComponent* Pivot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UArrowComponent* Arrow;

	UPROPERTY(BlueprintReadOnly)
	uint8 bIsActive : 1;

protected:
	virtual void BeginPlay() override;

	void Activate_Implementation() override;

public:	
	APortal();

	UFUNCTION(BlueprintPure)
	bool GetIsActive();

	UFUNCTION(BlueprintCallable)
	void SetIsActive(bool IsActive);

};
