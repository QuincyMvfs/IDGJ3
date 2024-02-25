// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SaveGameGISubsystem.generated.h"

/**
 * 
 */
UCLASS()
class IDGJ3_API USaveGameGISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	FString CurrentLevelName;

protected:
	UFUNCTION(BlueprintCallable)
	void SetCurrentLevelName(FString Name);

	UFUNCTION(BlueprintPure)
	FString GetCurrentLevelName();
};
