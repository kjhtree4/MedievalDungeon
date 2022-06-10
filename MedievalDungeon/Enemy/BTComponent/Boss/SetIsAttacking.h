// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SetIsAttacking.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API USetIsAttacking : public UBTTaskNode
{
	GENERATED_BODY()
public:
	USetIsAttacking();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector IsAttacking;
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory) override;

};
