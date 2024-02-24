// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "PortalsManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class IDGJ3_API UPortalsManagerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	APortal* GreenPortal;

	UPROPERTY()
	APortal* RedPortal;

public:
	UFUNCTION(BlueprintPure)
	APortal* GetGreenPortal();

	UFUNCTION(BlueprintPure)
	APortal* GetRedPortal();

	UFUNCTION(BlueprintCallable)
	void SetGreenPortal(APortal* Portal);

	UFUNCTION(BlueprintCallable)
	void SetRedPortal(APortal* Portal);
};
