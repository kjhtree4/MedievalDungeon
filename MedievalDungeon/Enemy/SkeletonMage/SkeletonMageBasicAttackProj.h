// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../MedievalDungeon.h"
#include "GameFramework/Actor.h"
#include "SkeletonMageBasicAttackProj.generated.h"

UCLASS()
class MEDIEVALDUNGEON_API ASkeletonMageBasicAttackProj : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkeletonMageBasicAttackProj();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
