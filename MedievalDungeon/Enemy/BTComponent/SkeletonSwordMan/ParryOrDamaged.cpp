// Fill out your copyright notice in the Description page of Project Settings.


#include "ParryOrDamaged.h"

UParryOrDamaged::UParryOrDamaged()
{
	NodeName = TEXT("ParryOrDamaged");
	Interval = 0.5f;
	RandomDeviation = 0.1f;
}

void UParryOrDamaged::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);



}