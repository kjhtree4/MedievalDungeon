// Fill out your copyright notice in the Description page of Project Settings.

#include "Mutant.h"
#include "MutantAnimInstance.h"


void UMutantAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();

	Mutant = Cast<AMutant>(Pawn);

	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();

	}
}

void UMutantAnimInstance::AnimNotify_Attack()
{
}

void UMutantAnimInstance::AnimNotify_AttackEnd()
{
}
