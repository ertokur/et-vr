// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ET_Types.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogET, Log, All);

//////////////////////////////////////////////////
//                  ENUMS                       //
//////////////////////////////////////////////////
UENUM(BlueprintType)
enum class ELogType : uint8
{
	LT_DISPLAY			UMETA(DisplayName = "Display"),
	LT_WARNING			UMETA(DisplayName = "Warning"),
	LT_ERROR			UMETA(DisplayName = "Error")
};