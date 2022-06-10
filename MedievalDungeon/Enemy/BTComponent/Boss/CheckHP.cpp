// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckHP.h"
#include "../../Boss/Boss.h"
#include "../../Boss/BossAIController.h"

UCheckHP::UCheckHP()
{
	NodeName = TEXT("CheckHP");
	Interval = 0.5f;
	RandomDeviation = 0.1f;
}

void UCheckHP::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	ABossAIController *BossAIController = Cast<ABossAIController>(OwnerComp.GetAIOwner());
	ABoss *Boss = Cast<ABoss>(BossAIController->GetPawn());

	if (IsValid(BossAIController) && IsValid(Boss))
	{

	}
	else
	{
		/*
		UE_LOG(LogTemp, Warning, TEXT("CheckDistanceFromplayer Error"))
		*/
		return;
	}

}