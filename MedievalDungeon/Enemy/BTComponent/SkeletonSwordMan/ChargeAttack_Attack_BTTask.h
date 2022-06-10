// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChargeAttack_Attack_BTTask.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API UChargeAttack_Attack_BTTask : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UChargeAttack_Attack_BTTask();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory) override;


};
