// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StatUI.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API UStatUI : public UUserWidget
{
	GENERATED_BODY()
	

public: 
	void UpdateHPBar();
	void UpdateEXPBar();
	void UpdateMPBar();
	void UpdateLevelText();
};
