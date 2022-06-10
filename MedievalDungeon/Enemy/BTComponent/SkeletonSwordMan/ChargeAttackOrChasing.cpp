// Fill out your copyright notice in the Description page of Project Settings.


#include "ChargeAttackOrChasing.h"

UChargeAttackOrChasing::UChargeAttackOrChasing()
{
	NodeName = TEXT("ChargeAttackOrChasing");
	Interval = 0.5f;
	RandomDeviation = 0.1f;
}

void UChargeAttackOrChasing::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);



}