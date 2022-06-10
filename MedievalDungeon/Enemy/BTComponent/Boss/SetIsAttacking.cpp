// Fill out your copyright notice in the Description page of Project Settings.


#include "SetIsAttacking.h"
#include "../../Boss/Boss.h"
#include "../../Boss/BossAIController.h"

USetIsAttacking::USetIsAttacking()
{
	NodeName = TEXT("USetIsAttacking");
}

EBTNodeResult::Type USetIsAttacking::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	ABossAIController *BossAIController = Cast<ABossAIController>(OwnerComp.GetAIOwner());
	ABoss *Boss = Cast<ABoss>(BossAIController->GetPawn());

	if (IsValid(BossAIController) && IsValid(Boss))
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