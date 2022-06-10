// Fill out your copyright notice in the Description page of Project Settings.

#include "../Enemy/EnemyParent.h"
#include "../Enemy/Boss/Boss.h"
#include "../ElementalMasterSkill/Projectile/BasicSkillProjectile.h"
#include "../ElementalMasterSkill/Projectile/MagicLauncherProjectile.h"
#include "Kismet/KismetMathLibrary.h"
#include "ElementalMaster.h"


AElementalMaster::AElementalMaster()
{
	Center = CreateDefaultSubobject<USceneComponent>(TEXT("Center"));
	BuffPos = CreateDefaultSubobject<USceneComponent>(TEXT("BuffPos"));

	TraceObjectTypeForProjectile.Add(EObjectTypeQuery::ObjectTypeQuery1);
	TraceObjectTypeForProjectile.Add(EObjectTypeQuery::ObjectTypeQuery2);

	TraceObjectTypeForEnemy.Add(EObjectTypeQuery::ObjectTypeQuery8);

	DashDistance = 15000.f;
	HealTime = 10.f;
	DecalSize = FVector(1.f, 1.f, 1.f);
	BlackHoleTime = 7.f;
	BlackHoleInterval = 0.5f;
	MagicFieldTime = 15.f;
	MagicFieldInterval = 1.5f;

	static ConstructorHelpers::FObjectFinder<UParticleSystem> PulseAttackPar(TEXT("ParticleSystem'/Game/MyParticle/P_Mage_MagicSphere.P_Mage_MagicSphere'"));
	if (PulseAttackPar.Succeeded())
	{
		PulseAttackParticle = PulseAttackPar.Object;
	}
	static ConstructorHelpers::FObjectFinder<UParticleSystem> MagicLauncherShowPar(TEXT("ParticleSystem'/Game/MyParticle/P_ky_shotShockwave.P_ky_shotShockwave'"));
	if (MagicLauncherShowPar.Succeeded())
	{
		MagicLauncherShockParticle = MagicLauncherShowPar.Object;
	}
	static ConstructorHelpers::FObjectFinder<UParticleSystem> BlackHole(TEXT("ParticleSystem'/Game/MyParticle/BlackHole.BlackHole'"));
	if (BlackHole.Succeeded())
	{
		BlackHoleParticle = BlackHole.Object;
	}
	static ConstructorHelpers::FObjectFinder<UParticleSystem> MagicField(TEXT("ParticleSystem'/Game/MyParticle/P_ky_magicCircle1.P_ky_magicCircle1'"));
	if (MagicField.Succeeded())
	{
		MagicFieldParticle = MagicField.Object;
	}
	static ConstructorHelpers::FObjectFinder<UParticleSystem> Heal(TEXT("ParticleSystem'/Game/MyParticle/P_Priest_Heal_Over_Time_3D.P_Priest_Heal_Over_Time_3D'"));
	if (Heal.Succeeded())
	{
		HealParticle = Heal.Object;
	}
	static ConstructorHelpers::FObjectFinder<UParticleSystem> HealStart(TEXT("ParticleSystem'/Game/MyParticle/P_Priest_AoE_Stun.P_Priest_AoE_Stun'"));
	if (HealStart.Succeeded())
	{
		HealStartParticle = HealStart.Object;
	}
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>ElementalMasterMesh(TEXT("SkeletalMesh'/Game/NewFolder/Ch28_nonPBR.Ch28_nonPBR'"));
	if(ElementalMasterMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(ElementalMasterMesh.Object);
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>BasicAttackMont1(TEXT("AnimMontage'/Game/MyWork/Animation/skillAnimation/BasicAttack1.BasicAttack1'"));
	if (BasicAttackMont1.Succeeded())
	{
		BasicAttack1 = BasicAttackMont1.Object;
	}
	static ConstructorHelpers::FObjectFinder<UAnimMontage>BasicAttackMont2(TEXT("AnimMontage'/Game/MyWork/Animation/skillAnimation/BasicAttack2.BasicAttack2'"));
	if (BasicAttackMont2.Succeeded())
	{
		BasicAttack2 = BasicAttackMont2.Object;
	}
	static ConstructorHelpers::FObjectFinder<UAnimMontage>BasicAttackMont3(TEXT("AnimMontage'/Game/MyWork/Animation/skillAnimation/BasicAttack3.BasicAttack3'"));
	if (BasicAttackMont3.Succeeded())
	{
		BasicAttack3 = BasicAttackMont3.Object;
	}
	static ConstructorHelpers::FObjectFinder<UAnimMontage>MagicFieldAttackMon(TEXT("AnimMontage'/Game/MyWork/Animation/skillAnimation/MagicFieldAttackMontage.MagicFieldAttackMontage'"));
	if (MagicFieldAttackMon.Succeeded())
	{
		MagicFieldAttackMontage = MagicFieldAttackMon.Object;
	}
	static ConstructorHelpers::FObjectFinder<UAnimMontage>BlackHoleAttackMon(TEXT("AnimMontage'/Game/MyWork/Animation/skillAnimation/BlackHoleAttackMontage.BlackHoleAttackMontage'"));
	if (BlackHoleAttackMon.Succeeded())
	{
		BlackHoleAttackMontage = BlackHoleAttackMon.Object;
	}
	static ConstructorHelpers::FObjectFinder<UAnimMontage>HealBuffMon(TEXT("AnimMontage'/Game/MyWork/Animation/skillAnimation/HealBuffMontage.HealBuffMontage'"));
	if (HealBuffMon.Succeeded())
	{
		HealBuffMontage = HealBuffMon.Object;
	}
	static ConstructorHelpers::FObjectFinder<UAnimMontage>MagicLauncherAttackMon(TEXT("AnimMontage'/Game/MyWork/Animation/skillAnimation/MagicLaucherAttackMontage.MagicLaucherAttackMontage'"));
	if (MagicLauncherAttackMon.Succeeded())
	{
		MagicLauncherAttackMontage = MagicLauncherAttackMon.Object;
	}
	static ConstructorHelpers::FObjectFinder<UAnimMontage>PulseAttackMon(TEXT("AnimMontage'/Game/MyWork/Animation/skillAnimation/PulseAttackMontage.PulseAttackMontage'"));
	if (PulseAttackMon.Succeeded())
	{
		PulseAttackMontage = PulseAttackMon.Object;
	}

}

void AElementalMaster::BeginPlay()
{
	Super::BeginPlay();

}


void AElementalMaster::SpawnBasicSkillProjectile()
{
	FRotator BasicProjectilRotation;
	float ProjectileDamage = SkillComponent->DamageArray[SkillComponent->CurrentSkillNum];

	TArray<AActor *> ActorToIgnore;
	FHitResult OutHit;
	if (UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(), SpringArm->GetComponentLocation(), SpringArm->GetComponentLocation() + UKismetMathLibrary::GetForwardVector(GetControlRotation())*100000.f, TraceObjectTypeForProjectile, false, ActorToIgnore, EDrawDebugTrace::None, OutHit, true))
	{
		BasicProjectilRotation = UKismetMathLibrary::FindLookAtRotation(GetMesh()->GetSocketLocation(FName(TEXT("Muzzle"))), OutHit.Location);
	}
	else 
	{
		BasicProjectilRotation = UKismetMathLibrary::FindLookAtRotation(GetMesh()->GetSocketLocation(FName(TEXT("Muzzle"))), OutHit.TraceEnd);
	}

	FTransform BasicSkillProjectileTransform = FTransform(BasicProjectilRotation, GetMesh()->GetSocketLocation(FName(TEXT("Muzzle"))), FVector(1.f, 1.f, 1.f));
	ABasicSkillProjectile *BasicSkillProjectile = GetWorld()->SpawnActorDeferred<ABasicSkillProjectile>(ABasicSkillProjectile::StaticClass(), BasicSkillProjectileTransform, this);
	BasicSkillProjectile->Damage = ProjectileDamage;
	UGameplayStatics::FinishSpawningActor(BasicSkillProjectile, BasicSkillProjectileTransform);
}

void AElementalMaster::PulseAttack2_Charge()
{
	WhenSomethingAttackStart();
	CanMove = false;

	UGameplayStatics::SpawnEmitterAttached(PulseAttackParticle, Center, FName(TEXT("None")), Center->GetComponentLocation(), FRotator(0.f, 0.f, 0.f), FVector(0.4f, 0.4f, 0.4f), EAttachLocation::KeepWorldPosition);
	AnimInstance->Montage_Play(PulseAttackMontage);
}

void AElementalMaster::PulseAttack2_Attack()
{
	float PulseAttackDamage = SkillComponent->DamageArray[SkillComponent->CurrentSkillNum];

	TArray<AActor *> ActorToIgnore;
	TArray<FHitResult> OutHits;
	UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(), Center->GetComponentLocation(), Center->GetComponentLocation(), 400.f, TraceObjectTypeForEnemy, false, ActorToIgnore, EDrawDebugTrace::None, OutHits, true);

	for (auto OutHit : OutHits)
	{
		if (Cast<AEnemyParent>(OutHit.Actor))
		{
			Cast<AEnemyParent>(OutHit.Actor)->Damaged(PulseAttackDamage, GetOwner());
		}
		else
		{
			Cast<ABoss>(OutHit.Actor)->Damaged(PulseAttackDamage);
		}
	}

}

void AElementalMaster::Dash_3()
{
	WhenSomethingAttackStart();
	CanMove = false;

	FVector LaunchVelocity = UKismetMathLibrary::GetForwardVector(FRotator(0.f, 0.f, CharacterMoveDirection.Yaw))*DashDistance;
	LaunchCharacter(LaunchVelocity, false, false);

	FTimerHandle DashFinishTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(DashFinishTimerHandle , this, &AElementalMaster::DashFisnish, 0.03, false);
}

void AElementalMaster::DashFisnish()
{
	GetCharacterMovement()->StopMovementImmediately();
	WhenSkillFinishCustom();
}

void AElementalMaster::MagicLauncher4_Charge()
{
	WhenSomethingAttackStart();
	CanMove = false;
	AnimInstance->Montage_Play(MagicLauncherAttackMontage);
}

void AElementalMaster::MagicLauncher4_Attack()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MagicLauncherShockParticle, FTransform(FRotator(0.f, 0.f, GetActorForwardVector().Z), GetMesh()->GetSocketLocation(FName(TEXT("Muzzle"))), FVector(1.5f, 1.5f, 1.5f)));
	
	float ProjectileDamage = SkillComponent->DamageArray[SkillComponent->CurrentSkillNum];
	FRotator ProjectileRotation;

	TArray<AActor *> ActorToIgnore;
	FHitResult OutHits;

	if (UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(), SpringArm->GetComponentLocation(),
		SpringArm->GetComponentLocation() + UKismetMathLibrary::GetForwardVector(GetControlRotation())*100000.f, TraceObjectTypeForProjectile, false, ActorToIgnore, EDrawDebugTrace::None, OutHits, true))
	{
		ProjectileRotation = UKismetMathLibrary::FindLookAtRotation(GetMesh()->GetSocketLocation(FName(TEXT("Muzzle"))), OutHits.Location);
	}
	else
	{
		ProjectileRotation = UKismetMathLibrary::FindLookAtRotation(GetMesh()->GetSocketLocation(FName(TEXT("Muzzle"))), OutHits.TraceEnd);
	}

	FTransform MagicLauncherProjectileTransform = FTransform(ProjectileRotation, GetMesh()->GetSocketLocation(FName(TEXT("Muzzle"))), FVector(1.f, 1.f, 1.f));
	AMagicLauncherProjectile *MagicLauncherProjectile = GetWorld()->SpawnActorDeferred<AMagicLauncherProjectile>(AMagicLauncherProjectile::StaticClass(), MagicLauncherProjectileTransform, this);
	MagicLauncherProjectile->Damage = ProjectileDamage;
	UGameplayStatics::FinishSpawningActor(MagicLauncherProjectile, MagicLauncherProjectileTransform);
}

void AElementalMaster::HealBuff5_Charge()
{
	WhenSomethingAttackStart();
	CanMove = false;

	AnimInstance->Montage_Play(HealBuffMontage);

	UGameplayStatics::SpawnEmitterAttached(HealStartParticle, GetMesh(), FName(TEXT("None")), GetMesh()->GetComponentLocation(), FRotator(0.f, 0.f, 0.f),FVector(0.5f,0.5f,0.5f), EAttachLocation::KeepWorldPosition);	
}

void AElementalMaster::HealBuff5_Heal()
{
	HealAmount = SkillComponent->DamageArray[SkillComponent->CurrentSkillNum];
	HealTimeReduce = HealTime;

	HealParticleComponent = UGameplayStatics::SpawnEmitterAttached(HealParticle, BuffPos, FName(TEXT("None")), BuffPos->GetComponentLocation(), FRotator(0.f, 0.f, 0.f), EAttachLocation::KeepWorldPosition);

	GetWorld()->GetTimerManager().SetTimer(HealTimerHandle, this, &AElementalMaster::HealBuffTimer, 1.f, true);
}

void AElementalMaster::HealBuffTimer()
{
	if (HealTimeReduce < 1.f)
	{
		HealParticleComponent->DestroyComponent();
		HealTimerHandle.Invalidate();
	}
	else
	{
		StatComponent->AddHP(HealAmount);
		HealTimeReduce--;
	}
}

void AElementalMaster::BlackHoleAttack6_Decal()
{
	WhenSomethingAttackStart();
	MaxDecalLocation = 1500.f;
	DecalScale = FVector(20.f, 20.f, 20.f);
	CanMove = false;
	ShowDecal = true;
	ReleaseFunctionNeed = true;
}

void AElementalMaster::BlackHoleAttack6_Charge()
{
	ShowDecal = false;
	ReleaseFunctionNeed = false;
	AnimInstance->Montage_Play(BlackHoleAttackMontage);
}

void AElementalMaster::BlackHoleAttack6_Attack()
{
	BlackHoleTimeReduce = BlackHoleTime;
	BlackHoleLocation = DecalLocationInMaxLength;

	GetWorld()->GetTimerManager().SetTimer(BlackHoleAttack6_DamagingTimerHandle, this, &AElementalMaster::BlackHoleAttack6_Damaging, BlackHoleInterval, true);
	GetWorld()->GetTimerManager().SetTimer(BlackHoleAttack6_GravityTimerHandle, this, &AElementalMaster::BlackHoleAttack6_Gravity, BlackHoleInterval, true);

	BlackHoleParticleComponent = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BlackHoleParticle, FTransform(FRotator(0.f, 0.f, 0.f), BlackHoleLocation, FVector(2.5f, 2.5f, 2.5f)));
}

void AElementalMaster::BlackHoleAttack6_Damaging()
{
	if (BlackHoleTimeReduce > 0.f)
	{
		BlackHoleTimeReduce = BlackHoleTimeReduce - BlackHoleInterval;
		BlackHoleDamage = SkillComponent->DamageArray[SkillComponent->CurrentSkillNum];

		TArray<AActor *> ActorToIgnore;
		TArray<FHitResult> OutHits;
		if (UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(), BlackHoleLocation, BlackHoleLocation, 700.f, TraceObjectTypeForEnemy, false, ActorToIgnore, EDrawDebugTrace::None, OutHits, true))
		{
			for (auto OutHit : OutHits)
			{
				if (Cast<AEnemyParent>(OutHit.Actor))
				{
					Cast<AEnemyParent>(OutHit.Actor)->Damaged(BlackHoleDamage, this);
				}
				else
				{
					Cast<ABoss>(OutHit.Actor)->Damaged(BlackHoleDamage);
				}
			}
		}
	}
	else
	{
		BlackHoleAttack6_GravityTimerHandle.Invalidate();
		BlackHoleAttack6_DamagingTimerHandle.Invalidate();
		BlackHoleParticleComponent->DestroyComponent();
	}
}

void AElementalMaster::BlackHoleAttack6_Gravity()
{
	TArray<AActor *> ActorToIgnore;
	TArray<FHitResult> OutHits;
	if (UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(), BlackHoleLocation, BlackHoleLocation, 700.f, TraceObjectTypeForEnemy, false, ActorToIgnore, EDrawDebugTrace::None, OutHits, true))
	{
		for (auto OutHit : OutHits)
		{
			if (Cast<AEnemyParent>(OutHit.Actor))
			{
				FVector Impulse = UKismetMathLibrary::ClampVectorSize(BlackHoleLocation - OutHit.Actor->GetActorLocation(), 10.f, 5000.f)
					* UKismetMathLibrary::MapRangeClamped(Cast<AEnemyParent>(OutHit.Actor)->GetMesh()->GetMass(), 50.f, 700.f, 5.f, 1.f);

				Cast<AEnemyParent>(OutHit.Actor)->GetCharacterMovement()->AddImpulse(Impulse, true);
			}
		}
	}
}

void AElementalMaster::MagicField7_Decal()
{
	WhenSomethingAttackStart();
	MaxDecalLocation = 1000.f;
	DecalScale = FVector(30.f, 30.f, 30.f);
	CanMove = false;
	ShowDecal = true;
	ReleaseFunctionNeed = true;
}

void AElementalMaster::MagicField7_Charge()
{
	ShowDecal = false;
	ReleaseFunctionNeed = false;
	AnimInstance->Montage_Play(MagicFieldAttackMontage);
}

void AElementalMaster::MagicField7_Attack()
{
	MagicFieldTimeReduce = MagicFieldTime;
	MagicFieldLocation = DecalLocationInMaxLength;

	GetWorld()->GetTimerManager().SetTimer(MagicField7_DamagingTimerHandle, this, &AElementalMaster::MagicField7_Damaging, MagicFieldInterval, true);
	MagicFieldParticleComponent = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MagicFieldParticle, FTransform(FRotator(0.f, 0.f, 0.f), MagicFieldLocation, FVector(8.f,8.f,8.f)));
}

void AElementalMaster::MagicField7_Damaging()
{
	if (MagicFieldTimeReduce > 0.f)
	{
		MagicFieldTimeReduce = MagicFieldTimeReduce - MagicFieldInterval;
		MagicFieldDamage = SkillComponent->DamageArray[SkillComponent->CurrentSkillNum];

		TArray<AActor *> ActorToIgnore;
		TArray<FHitResult> OutHits;
		if (UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(), MagicFieldLocation, MagicFieldLocation, 1000.f, TraceObjectTypeForEnemy, false, ActorToIgnore, EDrawDebugTrace::None, OutHits, true))
		{
			for (auto OutHit : OutHits)
			{
				if (Cast<AEnemyParent>(OutHit.Actor))
				{
					Cast<AEnemyParent>(OutHit.Actor)->Damaged(MagicFieldDamage, this);
				}
				else
				{
					Cast<ABoss>(OutHit.Actor)->Damaged(MagicFieldDamage);
				}
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MagicFieldParticle, FTransform(FRotator(0.f, 0.f, 0.f), OutHit.Actor->GetActorLocation(), FVector(1.f, 1.f, 1.f)));
			}
		}
	}
	else
	{
		MagicField7_DamagingTimerHandle.Invalidate();
		MagicFieldParticleComponent->DestroyComponent();
	}
}

void AElementalMaster::BasicAttack_1()
{
	if (CanBasicAttack)
	{
		if (DoBasicAttack)
		{
			if(CanNextBasicCombo)
			{
				CanNextBasicCombo = false;
			}
		}
		else 
		{
			DoBasicAttack = true;
			IsAttackForCharRotation = true;
		}

		switch (BasicComboCount)
		{
		case 0:
			BasicComboCount = 1;
			AnimInstance->Montage_Play(BasicAttack1);
			break;
		case 1:
			BasicComboCount = 2;
			AnimInstance->Montage_Play(BasicAttack2);
			break;
		case 2:
			BasicComboCount = 0;
			AnimInstance->Montage_Play(BasicAttack3);
			break;
		default:
			break;
		}
	}
}

void AElementalMaster::WhenSkillFinishCustom()
{
	BasicComboCount = 0;
	WhenSomethingAttackFinish();
	SkillComponent->SettingWhenSkillFinish();
	CanNextBasicCombo = false;
	DoBasicAttack = false;
}

void AElementalMaster::_1SkillExecute()
{
	BasicAttack_1();
}

void AElementalMaster::_2SkillExecute()
{
	PulseAttack2_Charge();
}

void AElementalMaster::_3SkillExecute()
{
	Dash_3();
}

void AElementalMaster::_4SkillExecute()
{
	MagicLauncher4_Charge();
}

void AElementalMaster::_5SkillExecute()
{
	HealBuff5_Charge();
}

void AElementalMaster::_6SkillExecute()
{
	if (ReleaseFunctionNeed)
	{
		BlackHoleAttack6_Charge();
	}
	else
	{
		BlackHoleAttack6_Decal();
	}
}

void AElementalMaster::_7SkillExecute()
{
	if (ReleaseFunctionNeed)
	{
		MagicField7_Charge();
	}
	else
	{
		MagicField7_Decal();
	}
}


void AElementalMaster::BasicComboAttackSave()
{
	CanNextBasicCombo = true;
}

void AElementalMaster::ResetBasicComboAttack()
{
	CanNextBasicCombo = false;
	DoBasicAttack = false;
	BasicComboCount = 0;

	WhenSomethingAttackFinish();
	SkillComponent->SettingWhenSkillFinish();
}
