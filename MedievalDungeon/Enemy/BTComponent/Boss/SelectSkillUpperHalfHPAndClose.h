// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SelectSkillUpperHalfHPAndClose.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API USelectSkillUpperHalfHPAndClose : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	USelectSkillUpperHalfHPAndClose();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector TargetActor;
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory) override;
};
