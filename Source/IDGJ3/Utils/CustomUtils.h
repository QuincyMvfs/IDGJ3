// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define PRINT_DEBUG_MESSAGE(text) if(GEngine) GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::White, text)
#define PRINT_DEBUG_MESSAGE_WITH_COLOR(text, color) if(GEngine) GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::color, text)

#define PRINT_INT_DEBUG_MESSAGE(number) if(GEngine) GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::White, FString::Printf(TEXT("%d"), number))
#define PRINT_INT_DEBUG_MESSAGE_WITH_COLOR(number, color) if(GEngine) GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::color, FString::Printf(TEXT("%d"), number))

#define PRINT_FLOAT_DEBUG_MESSAGE(number) if(GEngine) GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::White, FString::SanitizeFloat(number))
#define PRINT_FLOAT_DEBUG_MESSAGE_WITH_COLOR(number, color) if(GEngine) GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::color, FString::SanitizeFloat(number))