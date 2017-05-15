// Crashlytics Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2017 gameDNA. All Rights Reserved.

using System.IO;

namespace UnrealBuildTool.Rules
{
	public class Crashlytics : ModuleRules
	{
		public Crashlytics(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

			Definitions.Add("WITH_CRASHLYTICS=1");

			PrivateIncludePaths.Add("Crashlytics/Private");

            PublicDependencyModuleNames.AddRange(new string[] { "Engine", "Core", "CoreUObject" });
			PrivateIncludePathModuleNames.AddRange(new string[] { "Settings" });

			// Additional Frameworks and Libraries for iOS
			if (Target.Platform == UnrealTargetPlatform.IOS)
			{
				PublicAdditionalFrameworks.Add(
						new UEBuildFramework(
							"Fabric",
							"../ThirdParty/iOS/Fabric.embeddedframework.zip"
						)
				);

				PublicAdditionalFrameworks.Add(
						new UEBuildFramework(
							"Crashlytics",
							"../ThirdParty/iOS/Crashlytics.embeddedframework.zip"
						)
				);
			}
			// Additional Frameworks and Libraries for Android
			else if (Target.Platform == UnrealTargetPlatform.Android)
			{
				PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });
				string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, BuildConfiguration.RelativeEnginePath);
				AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginPath, "Crashlytics_UPL_Android.xml")));
			}
		}
	}
}
