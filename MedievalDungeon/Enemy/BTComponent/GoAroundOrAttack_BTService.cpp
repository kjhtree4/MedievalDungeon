// Fill out your copyright notice in the Description page of Project Settings.


#include "GoAroundOrAttack_BTService.h"


UGoAroundOrAttack_BTService::UGoAroundOrAttack_BTService()
{
	NodeName = TEXT("CheckHP");
	Interval = 0.5f;
	RandomDeviation = 0.1f;
}

void UGoAroundOrAttack_BTService::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);




}