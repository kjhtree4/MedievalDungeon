// Fill out your copyright notice in the Description page of Project Settings.

#include "SkeletonSwordMan.h"
#include "SkeletonSwordManAnimInstance.h"

void USkeletonSwordManAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();

	SkeletonSwordMan = Cast<ASkeletonSwordMan>(Pawn);

	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();
	}
}

void USkeletonSwordManAnimInstance::AnimNotify_Attack()
{
}

void USkeletonSwordManAnimInstance::AnimNotify_AttackEnd()
{
}

void USkeletonSwordManAnimInstance::AnimNotify_ComboAttack()
{
}

void USkeletonSwordManAnimInstance::AnimNotify_ChargeAttack()
{
}
