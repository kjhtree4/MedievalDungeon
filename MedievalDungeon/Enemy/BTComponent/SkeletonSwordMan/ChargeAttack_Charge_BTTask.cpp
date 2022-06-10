// Fill out your copyright notice in the Description page of Project Settings.


#include "ChargeAttack_Charge_BTTask.h"

#include "../../SkeletonSwordMan/SkeletonSwordMan.h"
#include "../../SkeletonSwordMan/SkeletonSwordManAIController.h"

UChargeAttack_Charge_BTTask::UChargeAttack_Charge_BTTask()
{
	NodeName = TEXT("UChargeAttack_Charge_BTTask");
}

EBTNodeResult::Type UChargeAttack_Charge_BTTask::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	ASkeletonSwordManAIController *SkeletonSwordManAIController = Cast<ASkeletonSwordManAIController>(OwnerComp.GetAIOwner());
	ASkeletonSwordMan *SkeletonSwordMan = Cast<ASkeletonSwordMan>(SkeletonSwordManAIController->GetPawn());

	if (IsValid(SkeletonSwordManAIController) && IsValid(SkeletonSwordMan))
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
