// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Setting/MedievalDungeonGameInstance.h"
#include "GameFramework/Actor.h"
#include "ParentSkill.generated.h"

UCLASS()
class MEDIEVALDUNGEON_API AParentSkill : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParentSkill();

	UPROPERTY(EditAnywhere)
		FSkillStatStructure SkillDetail;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
