// Crashlytics Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2017 gameDNA. All Rights Reserved.

#include "CrashlyticsPrivatePCH.h"
#include "CrashlyticsSettings.h"
#include "CrashlyticsBlueprintLibrary.h"
#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogCrashlytics);

#define LOCTEXT_NAMESPACE "Crashlytics"

class FCrashlytics : public ICrashlytics
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FCrashlytics, Crashlytics)

// Startup Module
void FCrashlytics::StartupModule()
{
	// Register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "Crashlytics",
			LOCTEXT("RuntimeSettingsName", "Crashlytics"),
			LOCTEXT("RuntimeSettingsDescription", "Configure the Crashlytics plugin"),
			GetMutableDefault<UCrashlyticsSettings>()
		);
	}

#if PLATFORM_ANDROID || PLATFORM_IOS
	UCrashlyticsBlueprintLibrary::InitCrashlytics();
#endif
}

// Shutdown Module
void FCrashlytics::ShutdownModule()
{
}


#undef LOCTEXT_NAMESPACE
