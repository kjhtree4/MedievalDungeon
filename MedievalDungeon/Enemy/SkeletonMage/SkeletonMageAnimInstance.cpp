// Fill out your copyright notice in the Description page of Project Settings.

#include "SkeletonMage.h"
#include "SkeletonMageAnimInstance.h"

void USkeletonMageAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();

	SkeletonMage = Cast<ASkeletonMage>(Pawn);

	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();
	}
}

void USkeletonMageAnimInstance::AnimNotify_Attack()
{
}

void USkeletonMageAnimInstance::AnimNotify_AttackEnd()
{
}

void USkeletonMageAnimInstance::AnimNotify_BombAttack()
{
}

void USkeletonMageAnimInstance::AnimNotify_RadialBlast()
{
}
