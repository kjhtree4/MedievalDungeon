// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicField_7.h"

AMagicField_7::AMagicField_7()
{
	SkillDetail.Name = FText::FromString(FString("MagicField"));
	SkillDetail.SkillNum = 7;
	SkillDetail.PreSkill.Add(4);
	SkillDetail.PreSkill.Add(5);
	SkillDetail.PreSkillsLevel.Add(5);
	SkillDetail.PreSkillsLevel.Add(5);
	SkillDetail.SkillPoint = 70;
	SkillDetail.HP = 0.f;
	SkillDetail.MP = 100.f;
	SkillDetail.Damage = 15.f;
	SkillDetail.DamageUpByLevel = 20.f;
	SkillDetail.CoolTime = 15.f;
	SkillDetail.CanCancle = false;

	static ConstructorHelpers::FObjectFinder<UTexture2D>IMG(TEXT("Texture2D'/Game/UI_Kit/Textures/icons/icon_spell_30.icon_spell_30'"));
	if (IMG.Succeeded())
	{
		SkillDetail.Image = IMG.Object;
	}

	SkillDetail.LevelNeed = 4;
	SkillDetail.Description = FText::FromString(FString("Can Damage Wide Range With Long Time"));
	SkillDetail.MaxSkillLevel = 30;
	SkillDetail.CanCurruptable = false;
	SkillDetail.ReleaseKeyNeeded = true;
}