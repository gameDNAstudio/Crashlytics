// Crashlytics Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2017 gameDNA. All Rights Reserved.

#pragma once

#include "CrashlyticsSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UCrashlyticsSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UCrashlyticsSettings(const FObjectInitializer& ObjectInitializer);

	// Api Key
	UPROPERTY(Config, EditAnywhere, Category = "Crashlytics", meta = (DisplayName = "Crashlytics Api Key"))
	FString CrashlyticsApiKey;
};
