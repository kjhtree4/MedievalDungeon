// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../MedievalDungeon.h"
#include "GameFramework/Actor.h"
#include "BasicSkillProjectile.generated.h"

UCLASS()
class MEDIEVALDUNGEON_API ABasicSkillProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasicSkillProjectile();
	
	UPROPERTY(EditAnywhere)
		float Damage;
	

	UPROPERTY(EditAnywhere)
		class USphereComponent *SphereCol;
	UPROPERTY(EditAnywhere)
		UParticleSystemComponent *ParticleSystem;
	UPROPERTY(EditAnywhere)
		class UProjectileMovementComponent *ProjectileMovement;
		

private:
	UPROPERTY(EditAnywhere)
		UParticleSystem *ExplosionParticle;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void DestroyThis();
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
