// Fill out your copyright notice in the Description page of Project Settings.

#include "../../Enemy/EnemyParent.h"
#include "../../Enemy/Boss/Boss.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "BasicSkillProjectile.h"

// Sets default values
ABasicSkillProjectile::ABasicSkillProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SphereCol = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCol"));
	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	

	RootComponent = SphereCol;
	ParticleSystem->SetupAttachment(SphereCol);

	static ConstructorHelpers::FObjectFinder<UParticleSystem>Particle(TEXT("ParticleSystem'/Game/MyParticle/BasicSkillProjectile.BasicSkillProjectile'"));
	if (Particle.Succeeded())
	{
		ParticleSystem->SetTemplate(Particle.Object);
	}
	static ConstructorHelpers::FObjectFinder<UParticleSystem>ExplosionPar(TEXT("ParticleSystem'/Game/MyParticle/BasicSkillBoom.BasicSkillBoom'"));
	if (ExplosionPar.Succeeded())
	{
		ExplosionParticle = ExplosionPar.Object;
	}

	RootComponent = SphereCol;
	ParticleSystem->SetupAttachment(SphereCol);

	SphereCol->SetRelativeScale3D(FVector(0.7f, 0.7f, 0.7f));
	ParticleSystem->SetRelativeScale3D(FVector(0.8f, 0.6f, 0.6f));
	
	ProjectileMovement->InitialSpeed = 2000.0f;
	ProjectileMovement->MaxSpeed = 2000.f;
	ProjectileMovement->ProjectileGravityScale = 0.f;

	SphereCol->SetCollisionProfileName(FName(TEXT("BulletCol")));

	OnActorBeginOverlap.AddDynamic(this, &ABasicSkillProjectile::ActorBeginOverlap);
}

// Called when the game starts or when spawned
void ABasicSkillProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerHandle DestroyTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(DestroyTimerHandle, this, &ABasicSkillProjectile::DestroyThis, 10.f, false);

}

void ABasicSkillProjectile::DestroyThis()
{
	this->Destroy();
	
}

void ABasicSkillProjectile::ActorBeginOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
	if (Cast<AEnemyParent>(OtherActor))
	{
		Cast<AEnemyParent>(OtherActor)->Damaged(Damage, GetOwner());
	}
	else
	{
		Cast<ABoss>(OtherActor)->Damaged(Damage);
	}
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticle, FTransform(FRotator(0.f, 0.f, 0.f), GetActorLocation(), FVector(1.f, 1.f, 1.f)));
	Destroy();
	
}

// Called every frame
void ABasicSkillProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

