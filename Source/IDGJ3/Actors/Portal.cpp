// Fill out your copyright notice in the Description page of Project Settings.


#include "Portal.h"

#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "IDGJ3/Utils/CustomUtils.h"

// Sets default values
APortal::APortal()
{
	PrimaryActorTick.bCanEverTick = false;

	Pivot = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Pivot;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Physical Body"));
	StaticMesh->SetupAttachment(Pivot);
	
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Pivot);
}

bool APortal::GetIsActive()
{
	return bIsActive;
}

void APortal::SetIsActive(bool IsActive)
{
	bIsActive = IsActive;

	if(!bIsActive)
	{
		OnPortalDeactivated.Broadcast();
	}
}

void APortal::BeginPlay()
{
	Super::BeginPlay();
}

void APortal::Activate_Implementation()
{
	IActivatable::Activate_Implementation();
	SetIsActive(true);
	
	OnPortalActivated.Broadcast();
}


