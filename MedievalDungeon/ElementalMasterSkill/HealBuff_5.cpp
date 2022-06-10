// Fill out your copyright notice in the Description page of Project Settings.


#include "HealBuff_5.h"

AHealBuff_5::AHealBuff_5()
{
	SkillDetail.Name = FText::FromString(FString("HealBuff"));
	SkillDetail.SkillNum = 5;
	SkillDetail.PreSkill.Add(3);
	SkillDetail.PreSkillsLevel.Add(1);
	SkillDetail.SkillPoint = 50;
	SkillDetail.HP = 0.f;
	SkillDetail.MP = 40.f;
	SkillDetail.Damage = 20.f;
	SkillDetail.DamageUpByLevel = 10.f;
	SkillDetail.CoolTime = 40.f;
	SkillDetail.CanCancle = false;

	static ConstructorHelpers::FObjectFinder<UTexture2D>IMG(TEXT("Texture2D'/Game/UI_Kit/Textures/icons/icon_spell_07.icon_spell_07'"));
	if (IMG.Succeeded())
	{
		SkillDetail.Image = IMG.Object;
	}

	SkillDetail.LevelNeed = 3;
	SkillDetail.Description = FText::FromString(FString("Can Heal Yourself"));
	SkillDetail.MaxSkillLevel = 30;
	SkillDetail.CanCurruptable = true;
	SkillDetail.ReleaseKeyNeeded = false;
}