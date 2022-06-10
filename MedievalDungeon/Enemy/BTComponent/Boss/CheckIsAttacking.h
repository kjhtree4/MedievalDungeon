// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CheckIsAttacking.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API UCheckIsAttacking : public UBTService
{
	GENERATED_BODY()
	
public:
	UCheckIsAttacking();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector IsAttacking;
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;

};
