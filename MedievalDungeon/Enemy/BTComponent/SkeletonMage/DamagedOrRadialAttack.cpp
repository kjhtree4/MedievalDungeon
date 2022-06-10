// Fill out your copyright notice in the Description page of Project Settings.


#include "DamagedOrRadialAttack.h"

UDamagedOrRadialAttack::UDamagedOrRadialAttack()
{
	NodeName = TEXT("UDamagedOrRadialAttack");
	Interval = 0.5f;
	RandomDeviation = 0.1f;
}

void UDamagedOrRadialAttack::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);



}