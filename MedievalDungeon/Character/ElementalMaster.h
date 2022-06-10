// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseCharacter.h"
#include "ElementalMaster.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALDUNGEON_API AElementalMaster : public ABaseCharacter
{
	GENERATED_BODY()


public:

	AElementalMaster();

	virtual void BasicAttack_1() override;
	virtual void WhenSkillFinishCustom() override;

	virtual void _1SkillExecute() override;
	virtual void _2SkillExecute() override;
	virtual void _3SkillExecute() override;
	virtual void _4SkillExecute() override;
	virtual void _5SkillExecute() override;
	virtual void _6SkillExecute() override;
	virtual void _7SkillExecute() override;
	

	void BasicComboAttackSave();
	void ResetBasicComboAttack();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
		USceneComponent *Center;
	UPROPERTY(EditAnywhere)
		USceneComponent *BuffPos;

	bool CanNextBasicCombo;
	bool DoBasicAttack;
	bool CombatMode;



private:
	int32 BasicComboCount;

	float DashDistance;
	float HealAmount;
	float HealTime;
	float HealTimeReduce;

	FTimerHandle HealTimerHandle;
	FTimerHandle BlackHoleAttack6_DamagingTimerHandle;
	FTimerHandle BlackHoleAttack6_GravityTimerHandle;

	FVector DecalSize;

	FVector BlackHoleLocation;
	float BlackHoleTime;
	float BlackHoleTimeReduce;
	float BlackHoleDamage;
	float BlackHoleInterval;

	UParticleSystem *PulseAttackParticle;
	UParticleSystem *MagicLauncherShockParticle;
	UParticleSystem *BlackHoleParticle;
	UParticleSystemComponent *BlackHoleParticleComponent;
	UParticleSystem *HealParticle;
	UParticleSystemComponent *HealParticleComponent;
	UParticleSystem *HealStartParticle;

	float MagicFieldTime;
	float MagicFieldTimeReduce;
	FTimerHandle MagicField7_DamagingTimerHandle;
	FVector MagicFieldLocation;
	UParticleSystem *MagicFieldParticle;
	UParticleSystemComponent *MagicFieldParticleComponent;
	float MagicFieldInterval;
	float MagicFieldDamage;

	TArray<TEnumAsByte<EObjectTypeQuery>> TraceObjectTypeForProjectile;
	TArray<TEnumAsByte<EObjectTypeQuery>> TraceObjectTypeForEnemy;

	
	UAnimMontage *MagicFieldAttackMontage;
	UAnimMontage *BlackHoleAttackMontage;
	UAnimMontage *HealBuffMontage;
	UAnimMontage *MagicLauncherAttackMontage;
	UAnimMontage *PulseAttackMontage;

	UAnimMontage *BasicAttack1;
	UAnimMontage *BasicAttack2;
	UAnimMontage *BasicAttack3;

private:
	
	UFUNCTION()
		void SpawnBasicSkillProjectile();

	UFUNCTION()
		void PulseAttack2_Charge();
	UFUNCTION()
		void PulseAttack2_Attack();
	
	UFUNCTION()
		void Dash_3();
	UFUNCTION()
		void DashFisnish();

	UFUNCTION()
		void MagicLauncher4_Charge();
	UFUNCTION()
		void MagicLauncher4_Attack();

	UFUNCTION()
		void HealBuff5_Charge();
	UFUNCTION()
		void HealBuff5_Heal();
	UFUNCTION()
		void HealBuffTimer();
	
	UFUNCTION()
		void BlackHoleAttack6_Decal();
	UFUNCTION()
		void BlackHoleAttack6_Charge();
	UFUNCTION()
		void BlackHoleAttack6_Attack();
	UFUNCTION()
		void BlackHoleAttack6_Damaging();
	UFUNCTION()
		void BlackHoleAttack6_Gravity();

	UFUNCTION()
		void MagicField7_Decal();
	UFUNCTION()
		void MagicField7_Charge();
	UFUNCTION()
		void MagicField7_Attack();
	UFUNCTION()
		void MagicField7_Damaging();

public:


};
