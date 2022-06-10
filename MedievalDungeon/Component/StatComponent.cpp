// Fill out your copyright notice in the Description page of Project Settings.


#include "StatComponent.h"


// Sets default values for this component's properties
UStatComponent::UStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Level = 1;
}


// Called when the game starts
void UStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UStatComponent::UpdateHPUI()
{
}

void UStatComponent::UpdateMPUI()
{
}

void UStatComponent::UpdateEXPUI()
{
}

void UStatComponent::UpdateLevel()
{
}

void UStatComponent::UpdateSkillPointText()
{
}

void UStatComponent::AddHP(float HPAmount)
{
}

void UStatComponent::AddMP(float MPAmount)
{
}

void UStatComponent::AddLevel(int32 LevelAmount)
{
}

void UStatComponent::AddSkillPoint(int32 SkillPointAmount)
{
}

void UStatComponent::AddEXP(int32 EXPAmount)
{
}

void UStatComponent::DecreaseHP(float HPAmount)
{
}

bool UStatComponent::DecreaseMP(float MPAmount)
{
	return false;
}

bool UStatComponent::DecreaseSkillPoint(int32 SkillPointAmount)
{
	return false;
}

bool UStatComponent::CheckCanUseThisSkill(float UseMP, float UseHP)
{
	return false;
}

void UStatComponent::SetStatsWhenSpawn()
{
}

void UStatComponent::ExecuteSkill(float HPUse, float MPUse)
{
}
