// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../MedievalDungeon.h"
#include "Animation/AnimInstance.h"
#include "MutantAnimInstance.generated.h"


/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API UMutantAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeUpdateAnimation(float DeltaSecond) override;

	float Speed;

	class AMutant *Mutant;


private:
	UFUNCTION()
		void AnimNotify_Attack();

	UFUNCTION()
		void AnimNotify_AttackEnd();

};
