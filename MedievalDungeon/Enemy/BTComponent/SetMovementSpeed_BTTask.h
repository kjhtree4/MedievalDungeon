// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SetMovementSpeed_BTTask.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API USetMovementSpeed_BTTask : public UBTTaskNode
{
	GENERATED_BODY()
	
public:

	USetMovementSpeed_BTTask();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector TargetActor;
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory) override;

};
