// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../MedievalDungeon.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class MEDIEVALDUNGEON_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	int32 temp;
	UPROPERTY(EditAnywhere)
		int32 ItemNumber;
	UPROPERTY(EditAnywhere)
		UBoxComponent *Sphere;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent *StaticMesh;
	UPROPERTY(EditAnywhere)
		UParticleSystemComponent *ParticleSystem;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetStaticMesh();
};
