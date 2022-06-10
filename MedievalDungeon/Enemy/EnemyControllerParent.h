// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../MedievalDungeon.h"
#include "AIController.h"
#include "EnemyControllerParent.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API AEnemyControllerParent : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyControllerParent();
	int temp;
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
		class UBehaviorTree *BTAsset;
};
