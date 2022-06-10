// Fill out your copyright notice in the Description page of Project Settings.

#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Components/WidgetComponent.h"
#include "SkeletonMage.h"

ASkeletonMage::ASkeletonMage()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>SKMESH(TEXT("SkeletalMesh'/Game/SkeletonCrew/Skeleton_Mage/Character/Skeleton_Mage.Skeleton_Mage'"));
	if (SKMESH.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SKMESH.Object);
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>ShootMontage(TEXT("AnimMontage'/Game/SkeletonCrew/Skeleton_Mage/Animations/SkeletonMageShotAttackMontage.SkeletonMageShotAttackMontage'"));
	if (ShootMontage.Succeeded())
	{
		AttackMontage.Add(ShootMontage.Object);
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>DieMontage(TEXT("AnimMontage'/Game/SkeletonCrew/Skeleton_Mage/Animations/SkeletonMageDieMontage.SkeletonMageDieMontage'"));
	if (DieMontage.Succeeded())
	{
		MontageDie = DieMontage.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>HitMontage(TEXT("AnimMontage'/Game/SkeletonCrew/Skeleton_Mage/Animations/SkeletonMageHitMontage.SkeletonMageHitMontage'"));
	if (HitMontage.Succeeded())
	{
		HittedMontage = HitMontage.Object;
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> Anim(TEXT("AnimBlueprint'/Game/CPPAnimInstances/SkeletonMageAnimInstance_.SkeletonMageAnimInstance__C'"));
	if (Anim.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(Anim.Class);
	}


	BombAttackDamage = 40.f;
	RadialBlastDamage = 25.f;

	RadialBlastSpawnDegree.Add(FRotator(0.f, 0.f, 0.f));
	RadialBlastSpawnDegree.Add(FRotator(0.f, 0.f, 45.f));
	RadialBlastSpawnDegree.Add(FRotator(0.f, 0.f, 90.f));
	RadialBlastSpawnDegree.Add(FRotator(0.f, 0.f, 135.f));
	RadialBlastSpawnDegree.Add(FRotator(0.f, 0.f, 180.f));
	RadialBlastSpawnDegree.Add(FRotator(0.f, 0.f, 225.f));
	RadialBlastSpawnDegree.Add(FRotator(0.f, 0.f, 270.f));
	RadialBlastSpawnDegree.Add(FRotator(0.f, 0.f, 315.f));

	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	DamageByAttackType.Add(30.f);//ShootDamage
	EXP = 100;
	HPMax = 300.f;

	SightConfig->SightRadius = 3000.f;
	SightConfig->LoseSightRadius = 3500.f;
	SightConfig->PeripheralVisionAngleDegrees = 60.f;
}

void ASkeletonMage::BasicAttack_Attack()
{
}

void ASkeletonMage::BombAttack_Charge()
{
}

void ASkeletonMage::BombAttack_Spawn()
{
}

void ASkeletonMage::RadialBlast_Charge()
{
}

void ASkeletonMage::RadialBlast_Attack()
{
}
