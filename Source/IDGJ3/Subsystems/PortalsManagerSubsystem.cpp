// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalsManagerSubsystem.h"

APortal* UPortalsManagerSubsystem::GetPortal(EPortalType PortalType)
{
	if (Portals.Contains(PortalType))
	{
		return Portals[PortalType];
	}

	return nullptr;
}

void UPortalsManagerSubsystem::SetPortal(EPortalType PortalType, APortal* Portal)
{
	Portals.Add(PortalType, Portal);
}
