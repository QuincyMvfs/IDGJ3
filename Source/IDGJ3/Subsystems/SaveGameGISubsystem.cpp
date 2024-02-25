// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveGameGISubsystem.h"

void USaveGameGISubsystem::SetCurrentLevelName(FString Name)
{
	CurrentLevelName = Name;
}

FString USaveGameGISubsystem::GetCurrentLevelName()
{
	return CurrentLevelName;
}
