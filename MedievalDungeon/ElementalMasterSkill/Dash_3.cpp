// Fill out your copyright notice in the Description page of Project Settings.


#include "Dash_3.h"

ADash_3::ADash_3()
{
	SkillDetail.Name = FText::FromString(FString("Dash"));
	SkillDetail.SkillNum = 3;
	SkillDetail.SkillPoint = 40;
	SkillDetail.HP = 0.f;
	SkillDetail.MP = 20.f;
	SkillDetail.Damage = 0.f;
	SkillDetail.DamageUpByLevel = 0.f;
	SkillDetail.CoolTime = 10.f;
	SkillDetail.CanCancle = false;

	static ConstructorHelpers::FObjectFinder<UTexture2D>IMG(TEXT("Texture2D'/Game/UI_Kit/Textures/icons/icon_spell_04.icon_spell_04'"));
	if (IMG.Succeeded())
	{
		SkillDetail.Image = IMG.Object;
	}

	SkillDetail.LevelNeed = 2;
	SkillDetail.Description = FText::FromString(FString("Can Dash"));
	SkillDetail.MaxSkillLevel = 1;
	SkillDetail.CanCurruptable = false;
	SkillDetail.ReleaseKeyNeeded = false;
}