// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackHole_6.h"

ABlackHole_6::ABlackHole_6()
{
	SkillDetail.Name = FText::FromString(FString("BlackHole"));
	SkillDetail.SkillNum = 6;
	SkillDetail.PreSkill.Add(4);
	SkillDetail.PreSkillsLevel.Add(5);
	SkillDetail.SkillPoint = 60;
	SkillDetail.HP = 0.f;
	SkillDetail.MP = 60.f;
	SkillDetail.Damage = 10.f;
	SkillDetail.DamageUpByLevel = 5.f;
	SkillDetail.CoolTime = 17.f;
	SkillDetail.CanCancle = false;

	static ConstructorHelpers::FObjectFinder<UTexture2D>IMG(TEXT("Texture2D'/Game/UI_Kit/Textures/icons/icon_spell_22.icon_spell_22'"));
	if (IMG.Succeeded())
	{
		SkillDetail.Image = IMG.Object;
	}

	SkillDetail.LevelNeed = 4;
	SkillDetail.Description = FText::FromString(FString("Can Pull Enemy Into Center"));
	SkillDetail.MaxSkillLevel = 30;
	SkillDetail.CanCurruptable = true;
	SkillDetail.ReleaseKeyNeeded = true;
}