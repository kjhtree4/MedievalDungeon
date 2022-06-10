// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../MedievalDungeon.h"
#include "../EnemyParent.h"
#include "Mutant.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API AMutant : public AEnemyParent
{
	GENERATED_BODY()
	
public:
	
	AMutant();

	virtual void BasicAttack_Attack() override;

protected:
	UPROPERTY(EditAnywhere)
		UBoxComponent *AttackCol;


};
