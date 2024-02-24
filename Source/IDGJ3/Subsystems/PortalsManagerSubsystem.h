// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "PortalsManagerSubsystem.generated.h"

/**
 * 
 */
class APortal;
UENUM(BlueprintType)
enum class EPortalType : uint8
{
	Null,
	Green,
	Red
};

UCLASS()
class IDGJ3_API UPortalsManagerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TMap<EPortalType, APortal*> PortalsMap;

public:	
	UFUNCTION(BlueprintPure)
	APortal* GetPortal(EPortalType PortalType);

	UFUNCTION(BlueprintCallable)
	void SetPortal(EPortalType PortalType, APortal* Portal);

	UFUNCTION(BlueprintPure)
	TMap<EPortalType, APortal*> GetPortalsMap();

	UFUNCTION()
	EPortalType GetKeyfromValue(APortal* Portal);
};
