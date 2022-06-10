// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../MedievalDungeon.h"
#include "GameFramework/Actor.h"

#include "SkeletonArcherProjectile.generated.h"

UCLASS()
class MEDIEVALDUNGEON_API ASkeletonArcherProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkeletonArcherProjectile();
	UPROPERTY(EditAnywhere)
		USceneComponent *DefaultSceneComponent;

	UPROPERTY(EditAnywhere)
		class UProjectileMovementComponent *ProjectileMovement;

	UPROPERTY(EditAnywhere)
		UParticleSystemComponent *ArrowParticle;

	UPROPERTY(EditAnywhere)
		UParticleSystem *HitNotCharacterParticle;

	UPROPERTY(EditAnywhere)
		UParticleSystem *HitCharacterParticle;
	
	UPROPERTY(EditAnywhere)
		UCapsuleComponent *ArrowCol;


	UPROPERTY(EditAnywhere)
		float Damage;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* selfComp, class AActor* otherActor, UPrimitiveComponent* otherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
