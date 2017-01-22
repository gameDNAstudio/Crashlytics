// Crashlytics Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2017 gameDNA studio. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "CrashlyticsBlueprintLibrary.generated.h"


UCLASS()
class CRASHLYTICS_API UCrashlyticsBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/**
	* Crashlytics initialization
	*/
	static void InitCrashlytics();

	/**
	* The easiest way to cause a crash - great for testing!
	*/
	UFUNCTION(BlueprintCallable, Category = Crashlytics, DisplayName = "Crashlytics Force Crash")
	static void ForceCrash();

	/**
	* The easiest way to cause a exception - great for testing!
	*/
	UFUNCTION(BlueprintCallable, Category = Crashlytics, DisplayName = "Crashlytics Force Exception")
	static void ForceException();

	/**
	* Personalize by user identifier
	*/
	UFUNCTION(BlueprintCallable, Category = Crashlytics, DisplayName = "Crashlytics Set User Identifier")
	static void SetUserIdentifier(FString Identifier);

	/**
	* Personalize by user email
	*/
	UFUNCTION(BlueprintCallable, Category = Crashlytics, DisplayName = "Crashlytics Set User Email")
	static void SetUserEmail(FString Email);

	/**
	* Personalize by user name
	*/
	UFUNCTION(BlueprintCallable, Category = Crashlytics, DisplayName = "Crashlytics Set User Name")
	static void SetUserName(FString Username);

	/**
	* Write custom log (dev and shipping build)
	*/
	UFUNCTION(BlueprintCallable, Category = Crashlytics, DisplayName = "Crashlytics Write Log")
	static void WriteLog(FString Log);
};
