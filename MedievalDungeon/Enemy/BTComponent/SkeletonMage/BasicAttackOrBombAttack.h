// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BasicAttackOrBombAttack.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API UBasicAttackOrBombAttack : public UBTService
{
	GENERATED_BODY()
public:
	UBasicAttackOrBombAttack();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector BasicAttackOrBombAttack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RoutineIncrease;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Routine;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RandomPercentage;

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;
};
