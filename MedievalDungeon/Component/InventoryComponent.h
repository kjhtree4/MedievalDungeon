// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../MedievalDungeon.h"
#include "../Setting/MedievalDungeonGameInstance.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEDIEVALDUNGEON_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	TArray<int32> InventoryItemNum;
	TArray<int32> InventoryItemCount;

	int32 GettedItemNum;

private:

	class ABaseCharacter *BaseCharacter;
	class AMainPlayerController *MainPlayerController;

	bool FindSameItem;
	bool UseAllThisItem;

	int32 InventoryDeletePos;

public:
	void ItemToInventory();

	void AddHP(float HP);
	void AddMP(float MP);
	void UseItem(FItemStructure ItemStructure);
		
};
