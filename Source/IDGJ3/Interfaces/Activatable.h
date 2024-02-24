// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Activatable.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI)
class UActivatable : public UInterface
{
	GENERATED_BODY()
};

class IDGJ3_API IActivatable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Activate();
};