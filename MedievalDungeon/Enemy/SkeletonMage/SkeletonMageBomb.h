// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../MedievalDungeon.h"
#include "GameFramework/Actor.h"
#include "SkeletonMageBomb.generated.h"

UCLASS()
class MEDIEVALDUNGEON_API ASkeletonMageBomb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	int32 temp;
	
	ASkeletonMageBomb();

	UPROPERTY(EditAnywhere)
		USceneComponent *SceneComponent;

	UPROPERTY(EditAnywhere)
		UDecalComponent *Decal;

	UPROPERTY(EditAnywhere)
		USphereComponent *BombCol;


	UPROPERTY(EditAnywhere)
		float Damage;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle BoomTimer;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
