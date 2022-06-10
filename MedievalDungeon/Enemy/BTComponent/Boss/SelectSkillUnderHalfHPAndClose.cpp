// Fill out your copyright notice in the Description page of Project Settings.


#include "SelectSkillUnderHalfHPAndClose.h"
#include "../../Boss/Boss.h"
#include "../../Boss/BossAIController.h"

USelectSkillUnderHalfHPAndClose::USelectSkillUnderHalfHPAndClose()
{
	NodeName = TEXT("USelectSkillUnderHalfHPAndClose");
}

EBTNodeResult::Type USelectSkillUnderHalfHPAndClose::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory)
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