// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../MedievalDungeon.h"
#include "Animation/AnimInstance.h"
#include "SkeletonSwordManAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API USkeletonSwordManAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:

	virtual void NativeUpdateAnimation(float DeltaSecond) override;

	float Speed;

	class ASkeletonSwordMan *SkeletonSwordMan;


private:
	UFUNCTION()
		void AnimNotify_Attack();
	UFUNCTION()
		void AnimNotify_AttackEnd();
	UFUNCTION()
		void AnimNotify_ComboAttack();
	UFUNCTION()
		void AnimNotify_ChargeAttack();

};
