// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../MedievalDungeon.h"
#include "../Component/InventoryComponent.h"
#include "../Component/SkillComponent.h"
#include "../Component/StatComponent.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


DECLARE_MULTICAST_DELEGATE(FQSkillPressedDelegate);
DECLARE_MULTICAST_DELEGATE(FESkillPressedDelegate);
DECLARE_MULTICAST_DELEGATE(FRSkillPressedDelegate);
DECLARE_MULTICAST_DELEGATE(FShiftSkillPressedDelegate);
DECLARE_MULTICAST_DELEGATE(FRightMouseSkillPressedDelegate);
DECLARE_MULTICAST_DELEGATE(FLeftMouseSkillPressedDelegate);
DECLARE_MULTICAST_DELEGATE(FQSkillReleasedDelegate);
DECLARE_MULTICAST_DELEGATE(FESkillReleasedDelegate);
DECLARE_MULTICAST_DELEGATE(FRSkillReleasedDelegate);
DECLARE_MULTICAST_DELEGATE(FShiftSkillReleasedDelegate);
DECLARE_MULTICAST_DELEGATE(FRightMouseSkillReleasedDelegate);
DECLARE_MULTICAST_DELEGATE(FLeftMouseSkillReleasedDelegate);
DECLARE_MULTICAST_DELEGATE(FHotBar1PressedDelegate);
DECLARE_MULTICAST_DELEGATE(FHotBar2PressedDelegate);
DECLARE_MULTICAST_DELEGATE(FHotBar3PressedDelegate);
DECLARE_MULTICAST_DELEGATE(FHotBar4PressedDelegate);
DECLARE_MULTICAST_DELEGATE(FProcessReleaseKeyWhenInterruptedDelegate);



UCLASS()
class MEDIEVALDUNGEON_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()


public:
	FQSkillPressedDelegate QSkillPressedDelegate;
	FESkillPressedDelegate ESkillPressedDelegate;
	FRSkillPressedDelegate RSkillPressedDelegate;
	FShiftSkillPressedDelegate ShiftSkillPressedDelegate;
	FRightMouseSkillPressedDelegate RightMouseSkillPressedDelegate;
	FLeftMouseSkillPressedDelegate LeftMouseSkillPressedDelegate;
	FQSkillReleasedDelegate QSkillReleasedDelegate;
	FESkillReleasedDelegate ESkillReleasedDelegate;
	FRSkillReleasedDelegate RSkillReleasedDelegate;
	FShiftSkillReleasedDelegate ShiftSkillReleasedDelegate;
	FRightMouseSkillReleasedDelegate RightMouseSkillReleasedDelegate;
	FLeftMouseSkillReleasedDelegate LeftMouseSkillReleasedDelegate;
	FHotBar1PressedDelegate HotBar1PressedDelegate;
	FHotBar2PressedDelegate HotBar2PressedDelegate;
	FHotBar3PressedDelegate HotBar3PressedDelegate;
	FHotBar4PressedDelegate HotBar4PressedDelegate;
	FProcessReleaseKeyWhenInterruptedDelegate ProcessReleaseKeyWhenInterruptedDelegate;

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	UPROPERTY(EditAnywhere)
		USpringArmComponent *SpringArm;
	UPROPERTY(EditAnywhere)
		UCameraComponent *Camera;
	UPROPERTY(EditAnywhere)
		UDecalComponent *Decal;

	UPROPERTY(EditAnywhere)
		USkillComponent *SkillComponent;
	UPROPERTY(EditAnywhere)
		UStatComponent *StatComponent;
	UPROPERTY(EditAnywhere)
		UInventoryComponent *InventoryComponent;

	int32 temp;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		UMaterial *DecalMat;

protected:
	bool CanBasicAttack;
	bool IsAttackForCharRotation;
	bool CanMove;
	bool ReleaseFunctionNeed;

	UAnimInstance *AnimInstance;

	UAnimMontage *DieMontage;
	UAnimMontage *InterruptMontage;
	

	FRotator CharacterMoveDirection;

	FVector DecalLocationInMaxLength;
	float MaxDecalLocation;
	FVector DecalLocationVector;
	FVector DecalScale;

	bool ShowSkillUI;

	bool ShowDecal;
private:

	bool CombatMode;

	FRotator ActorRotationWhenChangeToCombatMode;
	FRotator ControlRotationWhenChangeToCombatMode;

	TArray<TEnumAsByte<EObjectTypeQuery>> TraceObjectTypeForDecal;
	TArray<TEnumAsByte<EObjectTypeQuery>> ItemObjectType;

	class AMainPlayerController *PlayerController;

	float ItemDistance;
	int32 ItemClosest;

	bool IsDead;


	bool ShowInventoryUI;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	virtual void BasicAttack_1();
	virtual void WhenSkillFinishCustom();

	virtual void _1SkillExecute();
	virtual void _2SkillExecute();
	virtual void _3SkillExecute();
	virtual void _4SkillExecute();
	virtual void _5SkillExecute();
	virtual void _6SkillExecute();
	virtual void _7SkillExecute();
	FVector DecalLocation(float MaxLength);

	
	void InterruptProcess();

	void GetDamaged(float Damage);


	UFUNCTION()
		void BasicAttackPressed();
	UFUNCTION()
		void QSkillPressed();
	UFUNCTION()
		void ESkillPressed();
	UFUNCTION()
		void RSkillPressed();
	UFUNCTION()
		void ShiftSkillPressed();
	UFUNCTION()
		void RightMouseSkillPressed();
	UFUNCTION()
		void HotBar1Pressed();
	UFUNCTION()
		void HotBar2Pressed();
	UFUNCTION()
		void HotBar3Pressed();
	UFUNCTION()
		void HotBar4Pressed();
	UFUNCTION()
		void GetItemPressed();


	UFUNCTION()
		void BasicAttackReleased();
	UFUNCTION()
		void QSkillReleased();
	UFUNCTION()
		void ESkillReleased();
	UFUNCTION()
		void RSkillReleased();
	UFUNCTION()
		void ShiftSkillReleased();
	UFUNCTION()
		void RightMouseSkillReleased();

	UFUNCTION()
		void MoveForward(float AxisValue);
	UFUNCTION()
		void MoveRight(float AxisValue);
	UFUNCTION()
		void LookUp(float AxisValue);
	UFUNCTION()
		void LookRight(float AxisValue);
	

	void ChangeToNonCombatMovement();
	void ChangeToCombatMovement();


	void Die();

	void GetItem();

	void WhenSomethingAttackStart();
	void WhenSomethingAttackFinish();

	UFUNCTION()
		void GoToMenu();


};
