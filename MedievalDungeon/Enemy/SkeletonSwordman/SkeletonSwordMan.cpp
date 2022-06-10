// Fill out your copyright notice in the Description page of Project Settings.

#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Components/WidgetComponent.h"
#include "SkeletonSwordMan.h"

ASkeletonSwordMan::ASkeletonSwordMan()
{
	AttackCol = CreateDefaultSubobject<UBoxComponent>(TEXT("AttackCol"));

	static ConstructorHelpers::FObjectFinder<UAnimMontage>BasicAttackMontage(TEXT("AnimMontage'/Game/SkeletonCrew/Skeleton_Swordman/Animations/SkeletonSwordManBasicAttackMontage.SkeletonSwordManBasicAttackMontage'"));
	if (BasicAttackMontage.Succeeded())
	{
		AttackMontage.Add(BasicAttackMontage.Object);
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>ComboAttackMontage(TEXT("AnimMontage'/Game/SkeletonCrew/Skeleton_Swordman/Animations/SkeletonSwordManComboAttackMontage.SkeletonSwordManComboAttackMontage'"));
	if (ComboAttackMontage.Succeeded())
	{
		AttackMontage.Add(ComboAttackMontage.Object);
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>DieMontage(TEXT("AnimMontage'/Game/SkeletonCrew/Skeleton_Swordman/Animations/SkeletonSwordManDieMontage.SkeletonSwordManDieMontage'"));
	if (DieMontage.Succeeded())
	{
		MontageDie = DieMontage.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>HitMontage(TEXT("AnimMontage'/Game/SkeletonCrew/Skeleton_Swordman/Animations/SkeletonSworkdManHitMontage.SkeletonSworkdManHitMontage'"));
	if (HitMontage.Succeeded())
	{
		HittedMontage = HitMontage.Object;
	}

	static ConstructorHelpers::FObjectFinder<USkeletalMesh>SKMESH(TEXT("SkeletalMesh'/Game/SkeletonCrew/Skeleton_Swordman/Character/Skeleton_Swordman.Skeleton_Swordman'"));
	if (SKMESH.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SKMESH.Object);
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> Anim(TEXT("AnimBlueprint'/Game/CPPAnimInstances/SkeletonSwordManAnimInstance_.SkeletonSwordManAnimInstance__C'"));
	if (Anim.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(Anim.Class);
	}


	ChargeAttackDamage = 30.f;
	ParryPercentage = 0.4f;

	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	AttackCol->SetRelativeLocation(FVector(134.f, 0.f, -9.f));
	AttackCol->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	AttackCol->SetRelativeScale3D(FVector(1.25f, 4.75f, 2.93f));

	DamageByAttackType.Add(25.f);//basicAttackDamage
	DamageByAttackType.Add(25.f);//EachOfComboDamage

	EXP = 150;
	HPMax = 500.f;

	SightConfig->SightRadius = 3000.f;
	SightConfig->LoseSightRadius = 3500.f;
	SightConfig->PeripheralVisionAngleDegrees = 50.f;
}

void ASkeletonSwordMan::BasicAttack_Attack()
{
}

void ASkeletonSwordMan::Parry()
{
}

void ASkeletonSwordMan::ChargeAttack_Running()
{
}

void ASkeletonSwordMan::ChargeAttack_Attack()
{
}

void ASkeletonSwordMan::CalculateParryPercentage()
{
}

void ASkeletonSwordMan::ChargeAttackDamaging()
{
}

void ASkeletonSwordMan::Damaged(float Damage, AActor * Actor)
{



	Super::Damaged(Damage, Actor);

}
