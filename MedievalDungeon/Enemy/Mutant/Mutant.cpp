// Fill out your copyright notice in the Description page of Project Settings.


#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Components/WidgetComponent.h"
#include "Mutant.h"

AMutant::AMutant()
{
	AttackCol = CreateDefaultSubobject<UBoxComponent>(TEXT("AttackCol"));

	static ConstructorHelpers::FObjectFinder<UAnimMontage>PunchMontage(TEXT("AnimMontage'/Game/MyWork/Enemy/Mutant/MutantAnimation/MutantPunchMontage.MutantPunchMontage'"));
	if (PunchMontage.Succeeded())
	{
		AttackMontage.Add(PunchMontage.Object);
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>SwipMontage(TEXT("AnimMontage'/Game/MyWork/Enemy/Mutant/MutantAnimation/MutantSwipingMontage.MutantSwipingMontage'"));
	if (SwipMontage.Succeeded())
	{
		AttackMontage.Add(SwipMontage.Object);
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>DieMontage(TEXT("AnimMontage'/Game/MyWork/Enemy/Mutant/MutantAnimation/MutantDieMontage.MutantDieMontage'"));
	if (DieMontage.Succeeded())
	{
		MontageDie = DieMontage.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>HitMontage(TEXT("AnimMontage'/Game/MyWork/Enemy/Mutant/MutantAnimation/MutantHitMontage.MutantHitMontage'"));
	if (HitMontage.Succeeded())
	{
		HittedMontage = HitMontage.Object;
	}

	static ConstructorHelpers::FObjectFinder<USkeletalMesh>SKMESH(TEXT("SkeletalMesh'/Game/Mutant/mutant.mutant'"));
	if (SKMESH.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SKMESH.Object);
	}

	
	static ConstructorHelpers::FClassFinder<UAnimInstance> Anim(TEXT("AnimBlueprint'/Game/CPPAnimInstances/MutantAnimInstance_.MutantAnimInstance__C'"));
	if (Anim.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(Anim.Class);
	}
	

	DamageByAttackType.Add(10.f);//PunchDamage
	DamageByAttackType.Add(15.f);//SwipDamage
	EXP = 40.f;
	HPMax = 200.f;

	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	AttackCol->SetRelativeLocation(FVector(103.f, 0.f, -9.f));
	AttackCol->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	AttackCol->SetRelativeScale3D(FVector(1.25f, 3.25f, 1.75f));

	SightConfig->SightRadius = 1500.f;
	SightConfig->LoseSightRadius = 2000.f;
	SightConfig->PeripheralVisionAngleDegrees = 50.f;

}

void AMutant::BasicAttack_Attack()
{
}
