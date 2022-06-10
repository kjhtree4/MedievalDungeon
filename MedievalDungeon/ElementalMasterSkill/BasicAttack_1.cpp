// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicAttack_1.h"

ABasicAttack_1::ABasicAttack_1()
{
	SkillDetail.Name = FText::FromString(FString("BasicAttack"));
	SkillDetail.SkillNum = 1;
	SkillDetail.SkillPoint = 10;
	SkillDetail.HP = 0.f;
	SkillDetail.MP = 0.f;
	SkillDetail.Damage = 10.f;
	SkillDetail.DamageUpByLevel = 10.f;
	SkillDetail.CoolTime = 0.f;
	SkillDetail.CanCancle = true;
	
	static ConstructorHelpers::FObjectFinder<UTexture2D>IMG(TEXT("Texture2D'/Game/UI_Kit/Textures/icons/icon_spell_16.icon_spell_16'"));
	if (IMG.Succeeded())
	{
		SkillDetail.Image = IMG.Object;
	}
	
	SkillDetail.LevelNeed = 1;
	SkillDetail.Description= FText::FromString(FString("BasicAttack"));
	SkillDetail.MaxSkillLevel = 30;
	SkillDetail.CanCurruptable = true;
	SkillDetail.ReleaseKeyNeeded = false;
}