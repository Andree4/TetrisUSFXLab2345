// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.h"
#include "Piece.generated.h"

UCLASS()
class TETRISUSFX01_API APiece : public AActor
{
	GENERATED_BODY()
private:
	int Index;
	float posicionX;
	float posicionY;
	float posicionZ;

public:
	// Sets default values for this actor's properties
	APiece();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		class USceneComponent* SceneComponent;

	void Dismiss();

private:
	TArray<ABlock*> Blocks;

public:
	void SpawnBlocks();
	int GetIndex() const { return Index; }
	void setPosicionX(float _posicionX) { posicionX = _posicionX; }
	void setPosicionY(float _posicionY) { posicionY = _posicionY; }
	void setPosicionZ(float _posicionZ) { posicionZ = _posicionZ; }
	float getPosicionX() { return posicionX; }
	float getPosicionY() { return posicionY; }
	float getPosicionZ() { return posicionZ; }
};