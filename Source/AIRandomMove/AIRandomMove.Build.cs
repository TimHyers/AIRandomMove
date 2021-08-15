// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AIRandomMove : ModuleRules
{
	public AIRandomMove(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay",
			"GamePlayTasks",
			"AIModule",
			"NavigationSystem"
		});
	}
}
