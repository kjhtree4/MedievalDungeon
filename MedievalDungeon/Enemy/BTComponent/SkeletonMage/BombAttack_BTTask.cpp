// Fill out your copyright notice in the Description page of Project Settings.


#include "BombAttack_BTTask.h"
#include "../../SkeletonMage/SkeletonMage.h"
#include "../../SkeletonMage/SkeletonMageAIController.h"

UBombAttack_BTTask::UBombAttack_BTTask()
{
	NodeName = TEXT("USelectSkillUnderHalfHPAndFar");
}

EBTNodeResult::Type UBombAttack_BTTask::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	ASkeletonMageAIController *SkeletonMageAIController = Cast<ASkeletonMageAIController>(OwnerComp.GetAIOwner());
	ASkeletonMage *SkeletonMage = Cast<ASkeletonMage>(SkeletonMageAIController->GetPawn());

	if (IsValid(SkeletonMageAIController) && IsValid(SkeletonMage))
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
