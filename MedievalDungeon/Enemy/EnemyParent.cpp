// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyParent.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "EnemyControllerParent.h"
#include "Components/WidgetComponent.h"


// Sets default values
AEnemyParent::AEnemyParent()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));

	TickSecond = 0.3f;
	AIPerception->SetDominantSense(*SightConfig->GetSenseImplementation());
	AIPerception->ConfigureSense(*SightConfig);

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyParent::OnTargetDetected);


}

// Called when the game starts or when spawned
void AEnemyParent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyParent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyParent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyParent::BasicAttack_Attack()
{
}

void AEnemyParent::Damaged(float Damage, AActor * Actor)
{
}

void AEnemyParent::BasicAttackMoment(AActor * Target)
{
}

void AEnemyParent::SetIsAttacked()
{
}

void AEnemyParent::ResetIsAttacked()
{
}

void AEnemyParent::OnTargetDetected(AActor * actor, FAIStimulus const Stimulus)
{
}

void AEnemyParent::SetDie()
{
}

void AEnemyParent::Die()
{
}

void AEnemyParent::SpawnItem()
{
}

void AEnemyParent::WhenEndAttack()
{
}

