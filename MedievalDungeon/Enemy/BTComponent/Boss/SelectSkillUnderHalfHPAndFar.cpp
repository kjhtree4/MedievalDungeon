// Fill out your copyright notice in the Description page of Project Settings.


#include "SelectSkillUnderHalfHPAndFar.h"
#include "../../Boss/Boss.h"
#include "../../Boss/BossAIController.h"

USelectSkillUnderHalfHPAndFar::USelectSkillUnderHalfHPAndFar()
{
	NodeName = TEXT("USelectSkillUnderHalfHPAndFar");
}

EBTNodeResult::Type USelectSkillUnderHalfHPAndFar::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory)
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
