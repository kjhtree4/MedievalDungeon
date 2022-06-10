// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../MedievalDungeon.h"
#include "Perception/AIPerceptionTypes.h"
#include "GameFramework/Character.h"
#include "EnemyParent.generated.h"

UCLASS()
class MEDIEVALDUNGEON_API AEnemyParent : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyParent();

	UPROPERTY(EditAnywhere)
		class UWidgetComponent *HPWidget;

	UPROPERTY(EditAnywhere)
		class UAIPerceptionComponent *AIPerception;
	UPROPERTY(EditAnywhere)
		class UAISenseConfig_Sight* SightConfig;

	UPROPERTY(EditAnywhere)
		class UAnimInstance *AnimInstance;

	bool IsAttacked;
	bool IsDead;
	bool IsAttacking;

	AActor *SencedBaseCharacter;


protected:

	TArray<UAnimMontage *> AttackMontage;

	int32 AttackMontageArrayMaxIndex;

	TArray<float> DamageByAttackType;
	float HP;
	int32 EXP;
	int32 HowManySpawnItemMax;
	float HPMax;

	UPROPERTY(EditAnywhere)
		UAnimMontage *MontageDie;
	UPROPERTY(EditAnywhere)
		UAnimMontage *HittedMontage;

	float SightRange;
	float SightHalfDegree;
	float LoseSightRange;

	float TickSecond;
	float TickSecondReduce;

private:
	
	FTimerHandle LoseTargetTimerHandle;
	FTimerHandle DestroyTimerHandle;

	class EnemyControllerParent *AIControllerParent;

	int32 AttackTypeKey;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION()
		virtual void BasicAttack_Attack();
	UFUNCTION()
		virtual void Damaged(float Damage, AActor *Actor);
	UFUNCTION()
		void BasicAttackMoment(AActor *Target);
	UFUNCTION()
		void SetIsAttacked();
	UFUNCTION()
		void ResetIsAttacked();

	UFUNCTION()
		void OnTargetDetected(AActor* actor, FAIStimulus const Stimulus);
	UFUNCTION()
		void SetDie();
	UFUNCTION()
		void Die();

	UFUNCTION()
		void SpawnItem();
	UFUNCTION()
		void WhenEndAttack();

private:
	
};
