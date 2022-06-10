// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../MedievalDungeon.h"
#include "Animation/AnimInstance.h"
#include "SkeletonMageAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API USkeletonMageAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:

	virtual void NativeUpdateAnimation(float DeltaSecond) override;

	float Speed;

	class ASkeletonMage *SkeletonMage;

private:
	UFUNCTION()
		void AnimNotify_Attack();
	UFUNCTION()
		void AnimNotify_AttackEnd();
	UFUNCTION()
		void AnimNotify_BombAttack();
	UFUNCTION()
		void AnimNotify_RadialBlast();
};
