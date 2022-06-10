// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBasicAttack_BTTask.h"
#include "../EnemyParent.h"
#include "../EnemyControllerParent.h"

UEnemyBasicAttack_BTTask::UEnemyBasicAttack_BTTask()
{
	NodeName = TEXT("UEnemyBasicAttack_BTTask");
}

EBTNodeResult::Type UEnemyBasicAttack_BTTask::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory)
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