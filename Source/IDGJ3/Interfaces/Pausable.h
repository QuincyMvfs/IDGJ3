// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Pausable.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI, BlueprintType)
class UPausable : public UInterface
{
	GENERATED_BODY()
};

class IDGJ3_API IPausable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void TogglePause();
	
};