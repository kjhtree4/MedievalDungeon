// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../MedievalDungeon.h"
#include "../EnemyParent.h"
#include "SkeletonSwordMan.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API ASkeletonSwordMan : public AEnemyParent
{
	GENERATED_BODY()
	
public:
	ASkeletonSwordMan();

	virtual void BasicAttack_Attack() override;

	void Parry();
	void ChargeAttack_Running();
	void ChargeAttack_Attack();
	void CalculateParryPercentage();
	void ChargeAttackDamaging();

	virtual void Damaged(float Damage, AActor *Actor) override;



protected:
	UPROPERTY(EditAnywhere)
		UBoxComponent *AttackCol;

	bool IsParrying;
	float ChargeAttackDamage;
	float ParryPercentage;
};
