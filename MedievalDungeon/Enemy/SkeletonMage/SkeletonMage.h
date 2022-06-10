// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../MedievalDungeon.h"
#include "../EnemyParent.h"
#include "SkeletonMage.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API ASkeletonMage : public AEnemyParent
{
	GENERATED_BODY()

public:
	ASkeletonMage();

	virtual void BasicAttack_Attack() override;

	void BombAttack_Charge();
	void BombAttack_Spawn();
	void RadialBlast_Charge();
	void RadialBlast_Attack();
	int32 temp;

protected:
	int32 BombAttackDamage;
	int32 RadialBlastDamage;
	TArray<FRotator> RadialBlastSpawnDegree;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> ActionBarUI;


	
};
