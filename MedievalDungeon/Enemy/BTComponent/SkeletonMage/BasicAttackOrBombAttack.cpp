// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicAttackOrBombAttack.h"

UBasicAttackOrBombAttack::UBasicAttackOrBombAttack()
{
	NodeName = TEXT("UBasicAttackOrBombAttack");
	Interval = 0.5f;
	RandomDeviation = 0.1f;
}

void UBasicAttackOrBombAttack::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	

}