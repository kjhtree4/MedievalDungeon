// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../MedievalDungeon.h"
#include "../Setting/MedievalDungeonGameInstance.h"
#include "Components/ActorComponent.h"
#include "StatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEDIEVALDUNGEON_API UStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	int32 Level;
	float HP;
	float MP;
	int32 SkillPoint;
	int32 EXP;
	int32 EXPMax;

	float MaxHP;
	float MaxMP;

	TArray<int32> EXPMaxArray;
	TArray<int32> SkillPointArray;
	TArray<float> HPMaxArray;
	TArray<float> MPMaxArray;

private:
	class ABaseCharacter *BaseCharacter;
	class AMainPlayerController *MainPlayerController;

public:

	void UpdateHPUI();
	void UpdateMPUI();
	void UpdateEXPUI();
	void UpdateLevel();
	void UpdateSkillPointText();

	void AddHP(float HP);
	void AddMP(float MP);
	void AddLevel(int32 Level);
	void AddSkillPoint(int32 SkillPoint);
	void AddEXP(int32 EXP);

	void DecreaseHP(float HP);
	bool DecreaseMP(float MP);
	bool DecreaseSkillPoint(int32 SkillPoint);
	bool CheckCanUseThisSkill(float UseMP, float UseHP);

	void SetStatsWhenSpawn();
	
	void ExecuteSkill(float HPUse, float MPUse);


};
