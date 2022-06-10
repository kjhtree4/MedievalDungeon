// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../MedievalDungeon.h"
#include "../EnemyParent.h"
#include "SkeletonArcher.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API ASkeletonArcher : public AEnemyParent
{
	GENERATED_BODY()
	
public:
	ASkeletonArcher();

	virtual void BasicAttack_Attack() override;

protected:

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent *Skeleton_Crossbow;
};
