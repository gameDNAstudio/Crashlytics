// Crashlytics Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2016 gameDNA studio. All Rights Reserved.

#pragma once

#include "ModuleManager.h"

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
