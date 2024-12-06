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

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "SpawnMesh.generated.h"
/**
 * 
 */
UCLASS()
class ASSIMP2UNREALEXAMPLE_API USpawnMesh : public UObject
{
	GENERATED_BODY()
public:

  // Use the unreal plugin ProceduralMeshComponent to spawn a scene during runtime
  bool SpawnSection(TArray<FVector> Vertices, TArray<int32> Triangles);

  bool ClearSection();

  UProceduralMeshComponent* ProcMesh;
};
