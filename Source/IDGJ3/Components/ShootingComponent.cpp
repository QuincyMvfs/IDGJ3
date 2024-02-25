// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingComponent.h"

UShootingComponent::UShootingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FHitResult UShootingComponent::Shoot(const FVector& Start, const FVector& Direction, FColor Color)
{
	UWorld* World = GetWorld();
	if(!IsValid(World)) return FHitResult();

	FCollisionQueryParams CollisionParams(TEXT("ShootTrace"), false, GetOwner());
	FHitResult HitResult;
	
	bool ShotTrace = World->LineTraceSingleByChannel(HitResult, Start,Start + Direction * Range, ECC_GameTraceChannel1, CollisionParams);
	
	if(!ShotTrace)
	{
		HitResult.ImpactPoint = Start + Direction * Range * 100.0f;
		HitResult.Location = HitResult.ImpactPoint;
	}

	//DrawDebugLine(GetWorld(), Start, HitResult.ImpactPoint, Color, false, 3.0f, 0, 1.0f);
	return HitResult;
}

void UShootingComponent::BeginPlay()
{
	Super::BeginPlay();
}


