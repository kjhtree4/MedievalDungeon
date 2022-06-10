// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SelectSkillUpperHalfHPAndFar.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API USelectSkillUpperHalfHPAndFar : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	USelectSkillUpperHalfHPAndFar();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector TargetActor;
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory) override;
};
