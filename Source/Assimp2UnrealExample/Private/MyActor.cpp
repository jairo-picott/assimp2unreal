// Copyright (c) 2024 Jonas Mahler

// This file is part of Assimp2UnrealExample.

// Assimp2UnrealExample is free software: you can redistribute it and/or modify it under the terms 
// of the GNU General Public License as published by the Free Software Foundation, 
// either version 3 of the License, or (at your option) any later version.

// Assimp2UnrealExample is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
// See the GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along 
// with Assimp2UnrealExample. If not, see <https://www.gnu.org/licenses/>. 

#include "MyActor.h"
#include "Interfaces/IPluginManager.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize Mesh class
	Mesh = CreateDefaultSubobject<UImportMesh>("Mesh");

	// Initialize Spawn class
	Spawn = CreateDefaultSubobject<USpawnMesh>("Spawn");

	// Initialize Procedural Mesh Component
	Spawn->ProcMesh = CreateDefaultSubobject<UProceduralMeshComponent>("ProcMesh");
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin("Assimp2UnrealExample");

	if (!Plugin.IsValid())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Assimp2UnrealExample plugin not found"));
		return;
	}
	
	FString PluginPath = Plugin->GetContentDir();

	if (PluginPath == "")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Assimp2UnrealExample plugin path not found"));
		return;
	}

	FString MeshPath = FPaths::Combine(*PluginPath, TEXT("plane.obj"));
	// Convert Unreal filename to assimp compatible (backslash and forward slash)
	FPaths::MakeStandardFilename(MeshPath);
	
	if (!Mesh->OpenMesh(MeshPath))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Failed to open mesh"));
		return;
	}

	if (!Spawn->SpawnSection(Mesh->GetVertices(), Mesh->GetTriangles()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Failed to spawn mesh"));
		return;
	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

