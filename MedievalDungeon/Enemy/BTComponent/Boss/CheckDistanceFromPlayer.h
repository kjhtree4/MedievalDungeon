// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CheckDistanceFromPlayer.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API UCheckDistanceFromPlayer : public UBTService
{
	GENERATED_BODY()
	

public:
	UCheckDistanceFromPlayer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector TargetActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector IsInValidDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector IsClose;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CloseDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ValidDistance;

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;
};
