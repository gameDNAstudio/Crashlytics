// Crashlytics Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2017 gameDNA. All Rights Reserved.

#include "CrashlyticsBlueprintLibrary.h"
#include "CrashlyticsPrivatePCH.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include <android_native_app_glue.h>
#elif PLATFORM_IOS
#import <Fabric/Fabric.h>
#import <Crashlytics/Crashlytics.h>
#endif

UCrashlyticsBlueprintLibrary::UCrashlyticsBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UCrashlyticsBlueprintLibrary::InitCrashlytics()
{
#if PLATFORM_ANDROID

#elif PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{
		[Fabric with : @[[Crashlytics class]]];
	});
#endif
}

void UCrashlyticsBlueprintLibrary::ForceCrash()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ForceCrash", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#elif PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{
		[CrashlyticsKit crash];
	});
#endif
}

void UCrashlyticsBlueprintLibrary::ForceException()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ForceException", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#elif PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{
		[CrashlyticsKit throwException];
	});
#endif
}

void UCrashlyticsBlueprintLibrary::SetUserIdentifier(FString Identifier)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring IdentifierFinal = Env->NewStringUTF(TCHAR_TO_UTF8(*Identifier));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_SetUserIdentifier", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, IdentifierFinal);
		Env->DeleteLocalRef(IdentifierFinal);
	}
#elif PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{	
		[CrashlyticsKit setUserIdentifier : Identifier.GetNSString()];
	});
#endif
}

void UCrashlyticsBlueprintLibrary::SetUserEmail(FString Email)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring EmailFinal = Env->NewStringUTF(TCHAR_TO_UTF8(*Email));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_SetUserEmail", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, EmailFinal);
		Env->DeleteLocalRef(EmailFinal);
	}
#elif PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{
		[CrashlyticsKit setUserEmail : Email.GetNSString()];
	});
#endif
}

void UCrashlyticsBlueprintLibrary::SetUserName(FString Username)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring UsernameFinal = Env->NewStringUTF(TCHAR_TO_UTF8(*Username));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_SetUserName", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, UsernameFinal);
		Env->DeleteLocalRef(UsernameFinal);
	}
#elif PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{
		[CrashlyticsKit setUserName : Username.GetNSString()];
	});
#endif
}

void UCrashlyticsBlueprintLibrary::WriteLog(FString Log)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring LogFinal = Env->NewStringUTF(TCHAR_TO_UTF8(*Log));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_WriteLog", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, LogFinal);
		Env->DeleteLocalRef(LogFinal);
	}
#elif PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{
		CLS_LOG(@"%@", Log.GetNSString());
	});
#endif
}
