// Crashlytics Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2018 gameDNA Ltd. All Rights Reserved.

#pragma once

#include "ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCrashlytics, Log, All);

class ICrashlytics : public IModuleInterface
{
public:
	static inline ICrashlytics& Get()
	{
		return FModuleManager::LoadModuleChecked< ICrashlytics >("Crashlytics");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("Crashlytics");
	}
};
