// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/ProjectileMovementComponent.h"
#include "SkeletonMageRadialBlastProj.h"

// Sets default values
ASkeletonMageRadialBlastProj::ASkeletonMageRadialBlastProj()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Particle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComponent"));
	Col = CreateDefaultSubobject<UBoxComponent>(TEXT("Col"));
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));

	static ConstructorHelpers::FObjectFinder<UParticleSystem>Par(TEXT("ParticleSystem'/Game/AdvancedMagicFX13/Particles/P_ky_cutter2.P_ky_cutter2'"));
	if (Par.Succeeded())
	{
		Particle->SetTemplate(Par.Object);
	}

	RootComponent = Particle;
	Col->SetupAttachment(RootComponent);

	Particle->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	Col->SetRelativeLocation(FVector(-34.f, 0.f, 112.f));
	Col->SetRelativeScale3D(FVector(5.f, 2.f, 5.f));

	ProjectileMovement->InitialSpeed = 2000.f;
	ProjectileMovement->ProjectileGravityScale = 0.f;

}

// Called when the game starts or when spawned
void ASkeletonMageRadialBlastProj::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkeletonMageRadialBlastProj::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

