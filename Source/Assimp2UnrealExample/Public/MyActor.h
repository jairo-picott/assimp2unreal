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
#include "GameFramework/Actor.h"
#include "SpawnMesh.h"
#include "ImportMesh.h"
#include "MyActor.generated.h"

UCLASS()
class ASSIMP2UNREALEXAMPLE_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	UImportMesh* Mesh;

	UPROPERTY()
	USpawnMesh* Spawn;

};
