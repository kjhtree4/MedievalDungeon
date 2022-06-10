// Fill out your copyright notice in the Description page of Project Settings.

#include "../../Enemy/EnemyParent.h"
#include "../../Enemy/Boss/Boss.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "MagicLauncherProjectile.h"

// Sets default values
AMagicLauncherProjectile::AMagicLauncherProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SphereCol = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCol"));
	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));


	RootComponent = SphereCol;
	ParticleSystem->SetupAttachment(SphereCol);

	static ConstructorHelpers::FObjectFinder<UParticleSystem>Particle(TEXT("ParticleSystem'/Game/MyParticle/P_ky_fireBall.P_ky_fireBall'"));
	if (Particle.Succeeded())
	{
		ParticleSystem->SetTemplate(Particle.Object);
	}
	static ConstructorHelpers::FObjectFinder<UParticleSystem>ExplosionPar(TEXT("ParticleSystem'/Game/MyParticle/P_ky_explosion.P_ky_explosion'"));
	if (ExplosionPar.Succeeded())
	{
		ExplosionParticle = ExplosionPar.Object;
	}

	RootComponent = SphereCol;
	ParticleSystem->SetupAttachment(SphereCol);

	SphereCol->SetRelativeScale3D(FVector(1.2f, 1.2f, 1.2f));

	ProjectileMovement->InitialSpeed = 2500.0f;
	ProjectileMovement->MaxSpeed = 2500.f;
	ProjectileMovement->ProjectileGravityScale = 0.f;

	DamageRadius = 250.f;
	TraceObjectTypeForEnemy.Add(EObjectTypeQuery::ObjectTypeQuery8);

	SphereCol->SetCollisionProfileName(FName(TEXT("BulletCol")));

	OnActorBeginOverlap.AddDynamic(this, &AMagicLauncherProjectile::ActorBeginOverlap);
}

// Called when the game starts or when spawned
void AMagicLauncherProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerHandle DestroyTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(DestroyTimerHandle, this, &AMagicLauncherProjectile::DestroyThis, 10.f, false);
}

void AMagicLauncherProjectile::DestroyThis()
{
	this->Destroy();
}

void AMagicLauncherProjectile::ActorBeginOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
	TArray<AActor *> ActorToIgnore;
	TArray<FHitResult> OutHits;
	UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(), GetActorLocation(), GetActorLocation(), DamageRadius, TraceObjectTypeForEnemy, false, ActorToIgnore, EDrawDebugTrace::None, OutHits, true);

	for (auto OutHit : OutHits)
	{
		if (Cast<AEnemyParent>(OutHit.Actor))
		{
			Cast<AEnemyParent>(OutHit.Actor)->Damaged(Damage, GetOwner());
		}
		else
		{
			Cast<ABoss>(OutHit.Actor)->Damaged(Damage);
		}
	}
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticle, FTransform(FRotator(0.f, 0.f, 0.f), GetActorLocation(), FVector(1.7f, 1.7f, 1.7f)));

	this->Destroy();
}

// Called every frame
void AMagicLauncherProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

