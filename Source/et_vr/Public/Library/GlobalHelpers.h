// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "et_vr/Public/Types/ET_Types.h"
#include "GlobalHelpers.generated.h"

/**
 * 
 */
UCLASS()
class ET_VR_API UGlobalHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "ET-VR")
	static bool IsInEditor();
	
	UFUNCTION(BlueprintCallable, Category = "ET-VR", meta = (DisplayName = "Print Log"))
	static void PrintLog(ELogType Verbosity, UObject* From, FString Text, bool bPrintToScreen = false, float Time = 5.f);
	
	UFUNCTION(BlueprintPure, Category = "ET-VR")
	static FString GetGameVersion();
};
