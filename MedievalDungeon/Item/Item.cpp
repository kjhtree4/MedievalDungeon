// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<UBoxComponent>(TEXT("Sphere"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));

	RootComponent = Sphere;
	StaticMesh->SetupAttachment(Sphere);
	ParticleSystem->SetupAttachment(Sphere);

	static ConstructorHelpers::FObjectFinder<UParticleSystem>ItemParticle(TEXT("ParticleSystem'/Game/ParagonKallari/FX/Particles/Kallari/Abilities/Passive/FX/P_Stalker_Near_Death_Indicator.P_Stalker_Near_Death_Indicator'"));
	if (ItemParticle.Succeeded())
	{
		ParticleSystem->SetTemplate(ItemParticle.Object);
	}
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::SetStaticMesh()
{
}

