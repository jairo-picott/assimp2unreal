// Copyright Epic Games, Inc. All Rights Reserved.

#include "Assimp2UnrealExample.h"
#include "Misc/MessageDialog.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"
#include "Modules/ModuleManager.h"
#include "ExampleLibrary.h"


#define LOCTEXT_NAMESPACE "FAssimp2UnrealExampleModule"

void FAssimp2UnrealExampleModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
   // Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("Assimp2UnrealExample")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString LibraryPath;

	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/RuntimeMeshImportLibrary/x64/Release/assimp-vc143-mt.dll"));

	AssimpHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

	if (!AssimpHandle)
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load assimp - vc143 - mt.dll library"));
	}
}

void FAssimp2UnrealExampleModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(AssimpHandle);
	AssimpHandle = nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAssimp2UnrealExampleModule, Assimp2UnrealExample)