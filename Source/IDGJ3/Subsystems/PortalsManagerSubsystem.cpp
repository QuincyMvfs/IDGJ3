// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalsManagerSubsystem.h"

#include "IDGJ3/Actors/Portal.h"

void UPortalsManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	PortalsMap.Add(EPortalType::Green, nullptr);
	PortalsMap.Add(EPortalType::Red, nullptr);
	
}

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
	if(PortalsMap.Contains(PortalType))
	{
		PortalsMap[PortalType] = Portal;
	}
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

EPortalType UPortalsManagerSubsystem::GetOppositeKey(EPortalType CurrentPortalType) 
{
	switch (CurrentPortalType)
	{
	case EPortalType::Green:
		return EPortalType::Red;
		
	case EPortalType::Red:
		return EPortalType::Green;
		
	default:
		return EPortalType::Null; 
	}
}
