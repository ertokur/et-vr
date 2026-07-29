// Fill out your copyright notice in the Description page of Project Settings.


#include "Library/GlobalHelpers.h"

DEFINE_LOG_CATEGORY(LogET);

bool UGlobalHelpers::IsInEditor()
{
#if WITH_EDITOR
	return true;
#else
	return false;
#endif
}

void UGlobalHelpers::PrintLog(ELogType Verbosity, UObject* From, FString Text, bool bPrintToScreen, float Time)
{
	FString PrintText;

	if (From)
		PrintText += "[" + From->GetName() + "]: ";

	PrintText += Text;
	
	switch (Verbosity)
	{
	case ELogType::LT_DISPLAY:
		UE_LOG(LogET, Display, TEXT("%s"), *PrintText);	
		break;

	case ELogType::LT_WARNING:
		UE_LOG(LogET, Warning, TEXT("%s"), *PrintText);
		break;

	case ELogType::LT_ERROR:
		UE_LOG(LogET, Error, TEXT("%s"), *PrintText);
		break;
		
	default: break;
	}

	if (!bPrintToScreen)
		return;

	if (!GEngine)
		return;

	FColor PrintColor = FColor::White;

	switch (Verbosity)
	{
	case ELogType::LT_DISPLAY: PrintColor = FColor::Green; break;
	case ELogType::LT_WARNING: PrintColor = FColor::Yellow; break;
	case ELogType::LT_ERROR: PrintColor = FColor::Red; break;
	default: break;
	}

	GEngine->AddOnScreenDebugMessage(-1, Time, PrintColor, PrintText);
}

FString UGlobalHelpers::GetGameVersion()
{
	FString Version;

	if (GConfig)
	{
		GConfig->GetString(
		TEXT("/Script/EngineSettings.GeneralProjectSettings"),
		TEXT("ProjectVersion"),
		Version,
		GGameIni
		);
	}
	
	return Version;
}