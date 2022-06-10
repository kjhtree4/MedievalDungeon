// Fill out your copyright notice in the Description page of Project Settings.


#include "PulseAttack_2.h"

APulseAttack_2::APulseAttack_2()
{
	SkillDetail.Name = FText::FromString(FString("PulseAttack"));
	SkillDetail.SkillNum = 2;
	SkillDetail.SkillPoint = 20;
	SkillDetail.HP = 0.f;
	SkillDetail.MP = 20.f;
	SkillDetail.Damage = 30.f;
	SkillDetail.DamageUpByLevel = 30.f;
	SkillDetail.CoolTime = 7.f;
	SkillDetail.CanCancle = true;

	static ConstructorHelpers::FObjectFinder<UTexture2D>IMG(TEXT("Texture2D'/Game/UI_Kit/Textures/icons/icon_spell_13.icon_spell_13'"));
	if (IMG.Succeeded())
	{
		SkillDetail.Image = IMG.Object;
	}

	SkillDetail.LevelNeed = 2;
	SkillDetail.Description = FText::FromString(FString("Can Attack 360Degree"));
	SkillDetail.MaxSkillLevel = 30;
	SkillDetail.CanCurruptable = false;
	SkillDetail.ReleaseKeyNeeded = false;
}