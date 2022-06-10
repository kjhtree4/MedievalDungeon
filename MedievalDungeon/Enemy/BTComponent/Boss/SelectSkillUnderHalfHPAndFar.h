// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SelectSkillUnderHalfHPAndFar.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API USelectSkillUnderHalfHPAndFar : public UBTTaskNode
{
	GENERATED_BODY()
public:
	USelectSkillUnderHalfHPAndFar();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector TargetActor;
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory) override;
};
