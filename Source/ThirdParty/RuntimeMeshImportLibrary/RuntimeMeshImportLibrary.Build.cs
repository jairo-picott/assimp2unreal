// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class RuntimeMeshImportLibrary : ModuleRules
{
	public RuntimeMeshImportLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
		PublicSystemIncludePaths.Add("$(ModuleDir)/Public/RuntimeMeshImportLibrary");

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
		            // Add the import library
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "x64", "Release", "assimp-vc143-mt.lib"));

            // Delay-load the DLL, so we can load it from the right place first
            PublicDelayLoadDLLs.Add("assimp-vc143-mt.dll");

            // Ensure that the DLL is staged along with the executable
            RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/RuntimeMeshImportLibrary/Win64/assimp-vc143-mt.dll");
        }
	}
}
