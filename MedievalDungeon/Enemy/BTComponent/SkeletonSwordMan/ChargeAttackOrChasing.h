// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "ChargeAttackOrChasing.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API UChargeAttackOrChasing : public UBTService
{
	GENERATED_BODY()
	
public:
	UChargeAttackOrChasing();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector ChargeAttackOrChasing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RoutineIncrease;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Routine;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RandomPercentage;

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;
};
