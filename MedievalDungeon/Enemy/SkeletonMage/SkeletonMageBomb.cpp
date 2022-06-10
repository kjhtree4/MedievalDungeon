// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/DecalComponent.h"
#include "SkeletonMageBomb.h"

// Sets default values
ASkeletonMageBomb::ASkeletonMageBomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));

	BombCol = CreateDefaultSubobject<USphereComponent>(TEXT("BombCol"));

	Decal = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal"));

	static ConstructorHelpers::FObjectFinder<UMaterial>DECAL_MAT(TEXT("Material'/Game/TopDownBP/Blueprints/M_Cursor_Decal1_Blue.M_Cursor_Decal1_Blue'"));
	if (DECAL_MAT.Succeeded())
	{
		Decal->SetDecalMaterial(DECAL_MAT.Object);
	}

	RootComponent = SceneComponent;
	Decal->SetupAttachment(RootComponent);
	BombCol->SetupAttachment(Decal);

	Decal->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));
	Decal->SetRelativeScale3D(FVector(1.6f, 0.8f, 0.8f));
	Decal->DecalSize = FVector(128.f, 256.f, 256.f);

	BombCol->SetRelativeRotation(FRotator(90.f, -87.f, -87.f));
	BombCol->SetRelativeScale3D(FVector(1.25f, 1.25f, 1.25f));

	BombCol->SetSphereRadius(200.f);
}

// Called when the game starts or when spawned
void ASkeletonMageBomb::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkeletonMageBomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

