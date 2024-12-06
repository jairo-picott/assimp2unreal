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

#include "ImportMesh.h"
#include "assimp/scene.h"
#include "assimp/Importer.hpp"
#include "assimp/postprocess.h"


bool UImportMesh::OpenMesh(FString FilePath)
{
	// Delete possible previous data
	Vertices.Empty();
	Triangles.Empty();

	Assimp::Importer importer;
	const std::string& AFilePath = TCHAR_TO_UTF8(*FilePath);
	const aiScene* Scene = importer.ReadFile(AFilePath, aiProcessPreset_TargetRealtime_MaxQuality);
	if (!Scene)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Read file failed"));
		return false;
	}
	// Each node stores the index to one or more meshes. Take the first one.
	unsigned int SceneMeshIndex = Scene->mRootNode->mMeshes[0];
	// Meshes are stored in an array in scene. Index is position in array.
	aiMesh* Mesh = Scene->mMeshes[SceneMeshIndex];

	// Take all entries of imported assimp mesh that have the same number as vertice entries, including vertices.
	for (unsigned int i = 0; i < Mesh->mNumVertices; i++)
	{
		FVector VerticeBuffer = FVector(Mesh->mVertices[i].x, Mesh->mVertices[i].y, Mesh->mVertices[i].z);
		
		// Create vertice list of mesh.
		Vertices.Add(VerticeBuffer);
	}

	// Take all faces of assimp mesh that are triangles.
	for (uint32 i = 0; i < Mesh->mNumFaces; i++) {
		aiFace Face = Mesh->mFaces[i];
		// Take only if triangles
		if (Face.mNumIndices == 3)
		{
			// To invert the mesh visibility direction, change 0 and 2 triangles.
			Triangles.Add(Face.mIndices[2]);
			Triangles.Add(Face.mIndices[1]);
			Triangles.Add(Face.mIndices[0]);
		}
	}
	return true;
}

TArray<FVector> UImportMesh::GetVertices()
{
	return Vertices;
}


TArray<int32> UImportMesh::GetTriangles()
{
	return Triangles;
}

