// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IDGJ3/Interfaces/Activatable.h"
#include "Portal.generated.h"

class UBoxComponent;
class UArrowComponent;
class UStaticMeshComponent;
UCLASS()
class IDGJ3_API APortal : public AActor, public IActivatable
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* Pivot;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditDefaultsOnly)
	UArrowComponent* Arrow;
	
public:	
	APortal();

protected:
	virtual void BeginPlay() override;

	void Activate_Implementation() override;

};
