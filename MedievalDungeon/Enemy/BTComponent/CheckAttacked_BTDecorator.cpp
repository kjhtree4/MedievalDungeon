// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckAttacked_BTDecorator.h"
#include "../EnemyParent.h"
#include "../EnemyControllerParent.h"

UCheckAttacked_BTDecorator::UCheckAttacked_BTDecorator()
{

}

bool UCheckAttacked_BTDecorator::CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	AEnemyControllerParent *EnemyControllerParent = Cast<AEnemyControllerParent>(OwnerComp.GetAIOwner());
	AEnemyParent *EnemyParent = Cast<AEnemyParent>(EnemyControllerParent->GetPawn());

	if (IsValid(EnemyControllerParent) && IsValid(EnemyParent))
	{
		bool result = EnemyParent->IsAttacked;

		return result;
	}
	else
	{
		/*
		UE_LOG(LogTemp, Warning, TEXT("CheckDistanceFromplayer Error"))
		*/
		return false;
	}

}