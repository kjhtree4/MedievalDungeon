// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "../../MedievalDungeon.h"
#include "Animation/AnimInstance.h"
#include "SkeletonArcherAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API USkeletonArcherAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:

	virtual void NativeUpdateAnimation(float DeltaSecond) override;

	float Speed;

	class ASkeletonArcher *SkeletonArcher;

private:
	UFUNCTION()
		void AnimNotify_Attack();
	UFUNCTION()
		void AnimNotify_AttackEnd();
};
