// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "CheckAttacked_BTDecorator.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API UCheckAttacked_BTDecorator : public UBTDecorator
{
	GENERATED_BODY()
public:
	UCheckAttacked_BTDecorator();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory) const override;
	
};
