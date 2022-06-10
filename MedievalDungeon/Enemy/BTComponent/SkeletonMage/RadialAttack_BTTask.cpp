// Fill out your copyright notice in the Description page of Project Settings.


#include "RadialAttack_BTTask.h"
#include "../../SkeletonMage/SkeletonMage.h"
#include "../../SkeletonMage/SkeletonMageAIController.h"

URadialAttack_BTTask::URadialAttack_BTTask()
{
	NodeName = TEXT("URadialAttack_BTTask");
}

EBTNodeResult::Type URadialAttack_BTTask::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory)
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

