// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalsManagerSubsystem.h"

#include "IDGJ3/Actors/Portal.h"

APortal* UPortalsManagerSubsystem::GetPortal(EPortalType PortalType)
{
	if (PortalsMap.Contains(PortalType))
	{
		return PortalsMap[PortalType];
	}

	return nullptr;
}

void UPortalsManagerSubsystem::SetPortal(EPortalType PortalType, APortal* Portal)
{
	PortalsMap.Add(PortalType, Portal);
}

TMap<EPortalType, APortal*> UPortalsManagerSubsystem::GetPortalsMap()
{
	return PortalsMap;
}

EPortalType UPortalsManagerSubsystem::GetKeyfromValue(APortal* Portal)
{
	EPortalType FoundKey;

	for (const auto& Pair : PortalsMap)
	{
		if(APortal* IteratingPortal = Pair.Value)
		{
			if (IteratingPortal == Portal)
			{
				FoundKey = Pair.Key;
				return FoundKey;
			}
		}
	}
	return EPortalType::Null;
}
