// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillComponent.h"

// Sets default values for this component's properties
USkillComponent::USkillComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
	SkillLevelArray.Add(0); SkillLevelArray.Add(1); SkillLevelArray.Add(0); SkillLevelArray.Add(0); SkillLevelArray.Add(0); SkillLevelArray.Add(0); SkillLevelArray.Add(0); SkillLevelArray.Add(0);
	CoolTimeReduceArray.Init(0, 8);
	MPNeedArray.Init(0, 8);
	HPNeedArray.Init(0, 8);
	CoolTimeArray.Init(0, 8);

	TickTrickSec = 0.1f;

	CanCancle = true;
	SkillInterruptable = true;
	NoInterruptTimeWhenInterrupted = 7.f;

}


// Called when the game starts
void USkillComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USkillComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USkillComponent::SetStatArrayElem(int32 SkillNum, float Damage, float CoolTime, float MPNeed, float HPNeed)
{
}

void USkillComponent::SkillLevelUpProcess(int32 SkillNum, int32 HowManyLevelUp, float DamageUp)
{
}

void USkillComponent::ToTransferSpecificSkillsStatToSkillTree(int32 SkillNum, int32 SkillPointToLevelUp, bool Visibility)
{
}

void USkillComponent::SettingWhenSkillFinish()
{
}

void USkillComponent::ExecuteSkill(FSkillStatStructure SkillDetail, bool IsReleasedFunc, int32 SkillNum, bool CanCancle_, bool CanInterrupted)
{
}

void USkillComponent::GetInterrupted()
{
}

void USkillComponent::NoInterruptedModeProcess()
{
}

void USkillComponent::BackToIntteruptableMode()
{
}

bool USkillComponent::CheckCanExecuteThisSkill(int32 SkillNum)
{
	return false;
}

bool USkillComponent::CheckCoolTime(int32 SkillNum)
{
	return false;
}
