// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../MedievalDungeon.h"
#include "../Setting/MedievalDungeonGameInstance.h"
#include "Components/ActorComponent.h"
#include "SkillComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEDIEVALDUNGEON_API USkillComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USkillComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	TArray<int32> SkillLevelArray;

	TArray<float> CoolTimeReduceArray;

	bool DoingSkill;
	bool CanCancle;
	bool SkillInterruptable;
	bool CantInterruptabelMode;

	float NoInterruptTimeWhenInterrupted;

	FSkillStatStructure CurrentSkillDetail;

	float CurrentSkillNum;

	TArray<int32> DamageArray;

private:
	class ABaseCharacter *BaseCharacter;

	float ForTickSeconds;
	float TickTrickSec;

	class AMainPlayerController *PlayerController;

	TArray<int32> CoolTimeArray;
	TArray<int32> MPNeedArray;
	TArray<int32> HPNeedArray;

	FTimerHandle NoInterruptTimerHandle;

public:
	UFUNCTION()
		void SetStatArrayElem(int32 SkillNum, float Damage, float CoolTime, float MPNeed, float HPNeed);
	UFUNCTION()
		void SkillLevelUpProcess(int32 SkillNum, int32 HowManyLevelUp, float DamageUp);
	UFUNCTION()
		void ToTransferSpecificSkillsStatToSkillTree(int32 SkillNum, int32 SkillPointToLevelUp, bool Visibility);
	UFUNCTION()
		void SettingWhenSkillFinish();
	UFUNCTION()
		void ExecuteSkill(FSkillStatStructure SkillDetail, bool IsReleasedFunc, int32 SkillNum, bool CanCancle, bool CanInterrupted);
	UFUNCTION()
		void GetInterrupted();
	UFUNCTION()
		void NoInterruptedModeProcess();
	UFUNCTION()
		void BackToIntteruptableMode();

	UFUNCTION()
		bool CheckCanExecuteThisSkill(int32 SkillNum);
	UFUNCTION()
		bool CheckCoolTime(int32 SkillNum);



};
