// Fill out your copyright notice in the Description page of Project Settings.


#include "GoAround_BTTask.h"
#include "../EnemyParent.h"
#include "../EnemyControllerParent.h"

UGoAround_BTTask::UGoAround_BTTask()
{
	NodeName = TEXT("UGoAround_BTTask");
}

EBTNodeResult::Type UGoAround_BTTask::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	AEnemyControllerParent *EnemyControllerParent = Cast<AEnemyControllerParent>(OwnerComp.GetAIOwner());
	AEnemyParent *EnemyParent = Cast<AEnemyParent>(EnemyControllerParent->GetPawn());

	if (IsValid(EnemyControllerParent) && IsValid(EnemyParent))
	{
		return EBTNodeResult::Succeeded;
	}
	else
	{
		/*
		UE_LOG(LogTemp, Warning, TEXT("CheckDistanceFromplayer Error"))
		*/
		return EBTNodeResult::Failed;
	}
}