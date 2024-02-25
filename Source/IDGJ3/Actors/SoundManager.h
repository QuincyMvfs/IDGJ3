// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoundManager.generated.h"

UCLASS()
class IDGJ3_API ASoundManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASoundManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Shrink + Grow
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Scaling")
	TArray<USoundWave*> M_GrowSounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Scaling")
	TArray<USoundWave*> M_ShrinkSounds;

	// Grabbing
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Grabbing")
	TArray<USoundWave*> M_GrabSounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Grabbing")
	USoundWave* M_GrabbingSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Grabbing")
	TArray<USoundWave*> M_ThrowSounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Grabbing")
	TArray<USoundWave*> M_LetGoSounds;

	// Footsteps
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Player")
	TArray<USoundWave*> M_Footsteps;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Player")
	TArray<USoundWave*> M_ClickingSounds;

	// Object Dropping
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Object")
	TArray<USoundWave*> M_ObjectDropWoodSounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Object")
	TArray<USoundWave*> M_ObjectDropLeadSounds;

	// TV
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|TV")
	TArray<USoundWave*> M_TVTurnOnSounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|TV")
	TArray<USoundWave*> M_TVOnStaticSounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|TV")
	TArray<USoundWave*> M_TVTurnOffSounds;

	// Pressure Plate
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|PressurePlate")
	TArray<USoundWave*> M_PressurePlatePressedSounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|PressurePlate")
	TArray<USoundWave*> M_PressurePlateReleasedSounds;

	// Door
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Door")
	TArray<USoundWave*> M_DoorMovingSounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Door")
	TArray<USoundWave*> M_DoorOpenSounds;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Door")
	TArray<USoundWave*> M_DoorClosedSounds;

	// Music
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Music")
	USoundWave* GameMusic;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Music")
	USoundWave* MainMenuMusic;

	// Teleport
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Teleport")
	TArray<USoundWave*> M_TeleportStartedSounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Teleport")
	TArray<USoundWave*> M_TeleportingSounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Teleport")
	TArray<USoundWave*> M_TeleportedSounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Pause")
	TArray<USoundWave*> M_PauseSounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sounds|Pause")
	TArray<USoundWave*> M_UnPauseSounds;

};
