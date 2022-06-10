// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/ProjectileMovementComponent.h"
#include "SkeletonArcherProjectile.h"

// Sets default values
ASkeletonArcherProjectile::ASkeletonArcherProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));

	ArrowParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ArrowParticleComponent"));

	HitNotCharacterParticle = CreateDefaultSubobject<UParticleSystem>(TEXT("HitNotCharacterParticle"));		
	HitCharacterParticle = CreateDefaultSubobject<UParticleSystem>(TEXT("HitCharacterParticle"));
	
	ArrowCol = CreateDefaultSubobject<UCapsuleComponent>(TEXT("ArrowCol"));

	static ConstructorHelpers::FObjectFinder<UParticleSystem>HitNotCharPar(TEXT("ParticleSystem'/Game/ParagonKallari/FX/Particles/Kallari/Skins/Rogue/P_DaggerThrow_HitWorld_Rogue.P_DaggerThrow_HitWorld_Rogue'"));
	if (HitNotCharPar.Succeeded())
	{
		HitNotCharacterParticle = HitNotCharPar.Object;
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem>HitCharPar(TEXT("ParticleSystem'/Game/ParagonKallari/FX/Particles/Kallari/Abilities/DaggerThrow/FX/P_Kallari_DaggerThrow_HitPlayer.P_Kallari_DaggerThrow_HitPlayer'"));
	if (HitCharPar.Succeeded())
	{
		HitCharacterParticle= HitCharPar.Object;
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem>ArrowPar(TEXT("ParticleSystem'/Game/ParagonKallari/FX/Particles/Kallari/Abilities/DaggerThrow/FX/P_Kallari_Dagger_Targeting.P_Kallari_Dagger_Targeting'"));
	if (ArrowPar.Succeeded())
	{
		ArrowParticle->SetTemplate(ArrowPar.Object);
	}

	RootComponent = DefaultSceneComponent;
	ArrowParticle->SetupAttachment(RootComponent);
	ArrowCol->SetupAttachment(ArrowParticle);

	ArrowParticle->SetRelativeLocation(FVector(-115.f, 0.f, 0.f));
	ArrowParticle->SetRelativeRotation(FRotator(90.f, 180.f, 0.f));
	ArrowParticle->SetRelativeScale3D(FVector(20.f, 10.f, 7.f));

	ArrowCol->SetRelativeLocation(FVector(0.f, 0.f, 19.f));
	ArrowCol->SetRelativeScale3D(FVector(0.01f, 0.16f, 0.22f));

	ProjectileMovement->InitialSpeed = 800.f;
	ProjectileMovement->ProjectileGravityScale = 0.f;

	ArrowCol->OnComponentBeginOverlap.AddDynamic(this, &ASkeletonArcherProjectile::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ASkeletonArcherProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASkeletonArcherProjectile::OnOverlapBegin(UPrimitiveComponent * selfComp, AActor * otherActor, UPrimitiveComponent * otherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
}

// Called every frame
void ASkeletonArcherProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

