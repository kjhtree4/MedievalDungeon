// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "GoAroundOrAttack_BTService.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API UGoAroundOrAttack_BTService : public UBTService
{
	GENERATED_BODY()
public:

	UGoAroundOrAttack_BTService();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RandomPercentage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Routine;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RoutineIncrease;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector GoAroundOrAttack;
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;

};
