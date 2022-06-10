// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "GetPlayersAroundLocation_BTTask.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API UGetPlayersAroundLocation_BTTask : public UBTTaskNode
{
	GENERATED_BODY()
public:

	UGetPlayersAroundLocation_BTTask();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector PlayersAroundLocation;
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory) override;

};
