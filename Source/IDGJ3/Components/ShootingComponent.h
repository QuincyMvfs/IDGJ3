// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShootingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class IDGJ3_API UShootingComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Range = 5000.0f;
	
public:	
	UShootingComponent();

	UFUNCTION(BlueprintCallable)
	FHitResult Shoot(const FVector& Start, const FVector& Direction, FColor Color);

protected:
	virtual void BeginPlay() override;

	
};
