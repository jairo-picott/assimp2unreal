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


#include "SpawnMesh.h"

bool USpawnMesh::SpawnSection(TArray<FVector> Vertices, TArray<int32> Triangles)
{
	TArray<FVector> VertConv;
	// Converting factor from m to engine native cm
	double M2CM = 100.0f;

	// Converting factor from engine native cm to m
	double CM2M = 0.01f;


	for (int32 j = 0; j < Vertices.Num(); j++)
	{
		// Scale every vertice from m to cm
		VertConv.Add(Vertices[j] * M2CM);
	}

	int SectionNumber = 0;
	// Create the mesh with vertices and triangles only and add unitialized for normals, uv ...
	ProcMesh->CreateMeshSection(SectionNumber, VertConv, Triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>(), true);

	// Write position of first vertice of imported mesh
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("First Vertice X:	 " + FString::SanitizeFloat(VertConv[0].X * CM2M )));
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("First Vertice Y:	 " + FString::SanitizeFloat(VertConv[0].Y * CM2M )));
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("First Vertice Z:	 " + FString::SanitizeFloat(VertConv[0].Z * CM2M )));

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Added Mesh with section number: " + FString::FromInt(SectionNumber)));
	return true;
}

bool USpawnMesh::ClearSection()
{
	int SectionNumber = 0;
	ProcMesh->ClearMeshSection(SectionNumber);

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Cleared Mesh with section number: " + FString::FromInt(SectionNumber)));
	return true;
}




