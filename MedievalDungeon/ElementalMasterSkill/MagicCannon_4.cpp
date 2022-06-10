// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicCannon_4.h"

AMagicCannon_4::AMagicCannon_4() 
{
	SkillDetail.Name = FText::FromString(FString("MagicCannon"));
	SkillDetail.SkillNum = 4;
	SkillDetail.PreSkill.Add(2);
	SkillDetail.PreSkillsLevel.Add(5);
	SkillDetail.SkillPoint = 50;
	SkillDetail.HP = 0.f;
	SkillDetail.MP = 35.f;
	SkillDetail.Damage = 50.f;
	SkillDetail.DamageUpByLevel = 45.f;
	SkillDetail.CoolTime = 13.f;
	SkillDetail.CanCancle = true;

	static ConstructorHelpers::FObjectFinder<UTexture2D>IMG(TEXT("Texture2D'/Game/UI_Kit/Textures/icons/icon_spell_12.icon_spell_12'"));
	if (IMG.Succeeded())
	{
		SkillDetail.Image = IMG.Object;
	}

	SkillDetail.LevelNeed = 3;
	SkillDetail.Description = FText::FromString(FString("Can Attack Wide Range With High Damage"));
	SkillDetail.MaxSkillLevel = 30;
	SkillDetail.CanCurruptable = false;
	SkillDetail.ReleaseKeyNeeded = false;
}