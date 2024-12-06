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
#include "ImportMesh.generated.h"

/**
 * 
 */
UCLASS()
class ASSIMP2UNREALEXAMPLE_API UImportMesh : public UObject
{
	GENERATED_BODY()
public:

	// Open the mesh from external file.
	bool OpenMesh(FString FilePath);

	// Return the vertices of the mesh.
	TArray<FVector> GetVertices();

	// Return the triangles of the mesh.
	TArray<int32> GetTriangles();

private:
	// Vertices of the mesh in m from pivot point of mesh.
	UPROPERTY()
	TArray<FVector> Vertices;

    // Triangles of the mesh based on the vertices.
	UPROPERTY()
	TArray<int32> Triangles;
};
