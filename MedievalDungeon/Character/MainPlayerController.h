// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../MedievalDungeon.h"

#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	class USkillTree *SkillTreeUI;
	class UActionBar *ActionBarUI;
	class UStatUI *StatUI;
	class UInventory *InventoryUI;
	class UHotBar *HotBar;

	bool ShowSkillTreeUI;
	bool ShowInventoryUI;

	

public:
	virtual void SetupInputComponent() override;

	void UpdateSkillTreeDisableIMG();
	void TransferSkillStatToSkillTree();
	void UpdateActionBarCoolTimeBar();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
		void ShowSkillTreeUI_Pressed();
	UFUNCTION()
		void ShowInventory_Pressed();
	
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> SkillTreeUIClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> ActionBarUIClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> StatUIClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> InventoryUIClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> HotBarClass;






};
