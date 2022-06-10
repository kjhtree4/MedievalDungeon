// Fill out your copyright notice in the Description page of Project Settings.

#include "SkeletonArcher.h"
#include "SkeletonArcherAnimInstance.h"

void USkeletonArcherAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();

	SkeletonArcher = Cast<ASkeletonArcher>(Pawn);

	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();
	}
}

void USkeletonArcherAnimInstance::AnimNotify_Attack()
{
}

void USkeletonArcherAnimInstance::AnimNotify_AttackEnd()
{
}
