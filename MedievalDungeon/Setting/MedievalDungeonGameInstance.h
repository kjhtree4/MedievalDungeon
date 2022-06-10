// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../MedievalDungeon.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "MedievalDungeonGameInstance.generated.h"

/**
 * 
 */

USTRUCT()
struct FPlayerGrowthStructure : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float HP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SkillPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float EXPMax;
};


USTRUCT()
struct FItemStructure : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 ItemNumber;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MPAdd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float HPAdd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D *Image;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSoftObjectPtr<UStaticMesh> StaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SpawnPercentage;
};

USTRUCT()
struct FSkillStatStructure : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 SkillNum;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int32> PreSkill;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int32> PreSkillsLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 SkillPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float HP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DamageUpByLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CoolTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanCancle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D *Image;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 LevelNeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 MaxSkillLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanCurruptable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ReleaseKeyNeeded;
};


UCLASS()
class MEDIEVALDUNGEON_API UMedievalDungeonGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
};
