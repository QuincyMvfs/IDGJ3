// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalsManagerSubsystem.h"

APortal* UPortalsManagerSubsystem::GetGreenPortal()
{
	return GreenPortal;
}

APortal* UPortalsManagerSubsystem::GetRedPortal()
{
	return RedPortal;
}

void UPortalsManagerSubsystem::SetGreenPortal(APortal* Portal)
{
	GreenPortal = Portal;
}

void UPortalsManagerSubsystem::SetRedPortal(APortal* Portal)
{
	RedPortal = Portal;
}
