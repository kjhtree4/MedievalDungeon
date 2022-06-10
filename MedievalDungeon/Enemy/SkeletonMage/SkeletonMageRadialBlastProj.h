// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "../../MedievalDungeon.h"
#include "GameFramework/Actor.h"
#include "SkeletonMageRadialBlastProj.generated.h"

UCLASS()
class MEDIEVALDUNGEON_API ASkeletonMageRadialBlastProj : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkeletonMageRadialBlastProj();

	UPROPERTY(EditAnywhere)
		UParticleSystemComponent *Particle;

	UPROPERTY(EditAnywhere)
		UBoxComponent *Col;

	UPROPERTY(EditAnywhere)
		class UProjectileMovementComponent *ProjectileMovement;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
