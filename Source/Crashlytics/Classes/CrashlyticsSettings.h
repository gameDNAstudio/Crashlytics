// Crashlytics Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2016 gameDNA studio. All Rights Reserved.

#pragma once

#include "CrashlyticsSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UCrashlyticsSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UCrashlyticsSettings(const FObjectInitializer& ObjectInitializer);

	// Api Key
	UPROPERTY(Config, EditAnywhere, meta = (DisplayName = "Crashlytics Api Key"))
	FString CrashlyticsApiKey;
};
