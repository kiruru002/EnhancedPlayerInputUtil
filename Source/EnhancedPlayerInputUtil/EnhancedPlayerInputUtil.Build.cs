// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EnhancedPlayerInputUtil : ModuleRules
{
	public EnhancedPlayerInputUtil(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			}
		);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				//"Slate",
				//"SlateCore",
				// ... add private dependencies that you statically link with here ...	
				"EnhancedInput",
			}
		);
	}
}
