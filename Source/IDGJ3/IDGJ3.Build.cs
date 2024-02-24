// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class IDGJ3 : ModuleRules
{
	public IDGJ3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
