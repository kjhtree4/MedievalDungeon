// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CheckHP.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API UCheckHP : public UBTService
{
	GENERATED_BODY()
public:
	UCheckHP();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector LowerThanHalfHP;
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;

};
