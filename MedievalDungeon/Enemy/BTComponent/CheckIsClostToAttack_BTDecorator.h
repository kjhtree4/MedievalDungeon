// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "CheckIsClostToAttack_BTDecorator.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API UCheckIsClostToAttack_BTDecorator : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UCheckIsClostToAttack_BTDecorator();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector TargetActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Distance;
protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory) const override;

};
