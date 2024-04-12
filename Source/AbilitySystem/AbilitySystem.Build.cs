// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AbilitySystem : ModuleRules
{
	public AbilitySystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", 
	        "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput", 
	        "GameplayAbilities", "GameplayTags", "GameplayTasks", "UMG", "NavigationSystem" });
        
        PrivateDependencyModuleNames.AddRange(new string[] {  });
    }
}
