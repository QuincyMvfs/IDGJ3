// Copyright Epic Games, Inc. All Rights Reserved.

#include "IDGJ3GameMode.h"
#include "IDGJ3Character.h"
#include "UObject/ConstructorHelpers.h"

AIDGJ3GameMode::AIDGJ3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
