// Fill out your copyright notice in the Description page of Project Settings.

#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Components/WidgetComponent.h"
#include "SkeletonArcher.h"

ASkeletonArcher::ASkeletonArcher()
{
	Skeleton_Crossbow = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BOW"));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh>SKMESH(TEXT("SkeletalMesh'/Game/SkeletonCrew/Skeleton_Crossbowman/Character/skeleton_Crossbowman.Skeleton_Crossbowman'"));
	if (SKMESH.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SKMESH.Object);
	}


	static ConstructorHelpers::FObjectFinder<USkeletalMesh>Bow(TEXT("SkeletalMesh'/Game/SkeletonCrew/Skeleton_Crossbowman/Character/crossbow.Crossbow'"));
	if (Bow.Succeeded())
	{
		Skeleton_Crossbow->SetSkeletalMesh(Bow.Object);
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>ShootMontage(TEXT("AnimMontage'/Game/SkeletonCrew/Skeleton_Crossbowman/Animations/SkeletalArcherAttackMontage.SkeletalArcherAttackMontage'"));
	if (ShootMontage.Succeeded())
	{
		AttackMontage.Add(ShootMontage.Object);
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>DieMontage(TEXT("AnimMontage'/Game/SkeletonCrew/Skeleton_Crossbowman/Animations/SkeletalArcherDieMontage.SkeletalArcherDieMontage'"));
	if (DieMontage.Succeeded())
	{
		MontageDie = DieMontage.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>HitMontage(TEXT("AnimMontage'/Game/SkeletonCrew/Skeleton_Crossbowman/Animations/SkeletalArcherHittedMontage.SkeletalArcherHittedMontage'"));
	if (HitMontage.Succeeded())
	{
		HittedMontage = HitMontage.Object;
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> Anim(TEXT("AnimBlueprint'/Game/CPPAnimInstances/SkeletonArcherAnimInstance_.SkeletonArcherAnimInstance__C'"));
	if (Anim.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(Anim.Class);
	}

	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	DamageByAttackType.Add(20.f);//ShootDamage
	EXP = 70;
	HPMax = 200.f;

	SightConfig->SightRadius = 2000.f;
	SightConfig->LoseSightRadius = 2500.f;
	SightConfig->PeripheralVisionAngleDegrees = 60.f;
}

void ASkeletonArcher::BasicAttack_Attack()
{
}
