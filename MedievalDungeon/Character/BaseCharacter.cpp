// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/DecalComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "../Item/Item.h"
#include "MainPlayerController.h"
#include "../UI/StatUI.h"
#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Decal = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal"));
	SkillComponent = CreateDefaultSubobject<USkillComponent>(TEXT("Skillcomponent"));
	StatComponent = CreateDefaultSubobject<UStatComponent>(TEXT("StatComponent"));
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Decal->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	SpringArm->SetRelativeLocation(FVector(0.f, 0, 63.f));
	SpringArm->TargetArmLength = 600.f;
	SpringArm->bUsePawnControlRotation = true;

	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	Decal->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
	Decal->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));
	Decal->SetRelativeScale3D(FVector(2.75f, 1.f, 1.f));
	Decal->DecalSize = FVector(16.f, 32.f, 32.f);

	GetCapsuleComponent()->SetCollisionProfileName(FName(TEXT("PlayerCol")));

	TraceObjectTypeForDecal.Add(EObjectTypeQuery::ObjectTypeQuery1);
	TraceObjectTypeForDecal.Add(EObjectTypeQuery::ObjectTypeQuery2);

	ItemObjectType.Add(EObjectTypeQuery::ObjectTypeQuery10);

	ItemDistance = 10000000.f;
	ItemClosest = -1;

	static ConstructorHelpers::FObjectFinder<UMaterial>DECAL_MAT(TEXT("Material'/Game/TopDownBP/Blueprints/M_Cursor_Decal_Green.M_Cursor_Decal_Green'"));
	if (DECAL_MAT.Succeeded())
	{
		DecalMat = DECAL_MAT.Object;
		Decal->SetDecalMaterial(DecalMat);
	}

	CanMove = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<AMainPlayerController>(GetController());
	
	AnimInstance = GetMesh()->GetAnimInstance();

	PlayerController->StatUI->UpdateHPBar();
	PlayerController->StatUI->UpdateEXPBar();
	PlayerController->StatUI->UpdateMPBar();
	PlayerController->StatUI->UpdateLevelText();

}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!IsDead)
	{
		if (IsAttackForCharRotation)
		{
			ChangeToCombatMovement();
		}
		else
		{
			ChangeToNonCombatMovement();
		}
	}

	if (CombatMode)
	{
		SetActorRotation(UKismetMathLibrary::RInterpTo(ActorRotationWhenChangeToCombatMode, ControlRotationWhenChangeToCombatMode, DeltaTime, 5.f));
	}
	else
	{
		CharacterMoveDirection = GetActorRotation();
	}

	if (ShowDecal)
	{
		Decal->SetVisibility(true);
		DecalLocationInMaxLength = DecalLocation(MaxDecalLocation);
		Decal->SetWorldLocation(DecalLocationInMaxLength);
		Decal->SetWorldScale3D(DecalScale);
	}
	else
	{
		Decal->SetVisibility(false);
	}
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Lookup"), this, &ABaseCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &ABaseCharacter::LookRight);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ABaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ABaseCharacter::MoveRight);

	PlayerInputComponent->BindAction(TEXT("BasicAttack"), EInputEvent::IE_Pressed, this, &ABaseCharacter::BasicAttackPressed);
	PlayerInputComponent->BindAction(TEXT("QSkill"), EInputEvent::IE_Pressed, this, &ABaseCharacter::BasicAttackPressed);
	PlayerInputComponent->BindAction(TEXT("ESkill"), EInputEvent::IE_Pressed, this, &ABaseCharacter::BasicAttackPressed);
	PlayerInputComponent->BindAction(TEXT("RSkill"), EInputEvent::IE_Pressed, this, &ABaseCharacter::BasicAttackPressed);
	PlayerInputComponent->BindAction(TEXT("ShiftSkill"), EInputEvent::IE_Pressed, this, &ABaseCharacter::BasicAttackPressed);
	PlayerInputComponent->BindAction(TEXT("RightMouseSkill"), EInputEvent::IE_Pressed, this, &ABaseCharacter::BasicAttackPressed);
	PlayerInputComponent->BindAction(TEXT("ShowSkillTreeUI"), EInputEvent::IE_Pressed, this, &ABaseCharacter::BasicAttackPressed);
	PlayerInputComponent->BindAction(TEXT("GetItem"), EInputEvent::IE_Pressed, this, &ABaseCharacter::BasicAttackPressed);
	PlayerInputComponent->BindAction(TEXT("HotBar1"), EInputEvent::IE_Pressed, this, &ABaseCharacter::BasicAttackPressed);
	PlayerInputComponent->BindAction(TEXT("HotBar2"), EInputEvent::IE_Pressed, this, &ABaseCharacter::BasicAttackPressed);
	PlayerInputComponent->BindAction(TEXT("HotBar3"), EInputEvent::IE_Pressed, this, &ABaseCharacter::BasicAttackPressed);
	PlayerInputComponent->BindAction(TEXT("HotBar4"), EInputEvent::IE_Pressed, this, &ABaseCharacter::BasicAttackPressed);
	PlayerInputComponent->BindAction(TEXT("ShowInventory"), EInputEvent::IE_Pressed, this, &ABaseCharacter::BasicAttackPressed);

	PlayerInputComponent->BindAction(TEXT("BasicAttack"), EInputEvent::IE_Released, this, &ABaseCharacter::BasicAttackReleased);
	PlayerInputComponent->BindAction(TEXT("QSkill"), EInputEvent::IE_Released, this, &ABaseCharacter::BasicAttackReleased);
	PlayerInputComponent->BindAction(TEXT("ESkill"), EInputEvent::IE_Released, this, &ABaseCharacter::BasicAttackReleased);
	PlayerInputComponent->BindAction(TEXT("RSkill"), EInputEvent::IE_Released, this, &ABaseCharacter::BasicAttackReleased);
	PlayerInputComponent->BindAction(TEXT("ShiftSkill"), EInputEvent::IE_Released, this, &ABaseCharacter::BasicAttackReleased);
	PlayerInputComponent->BindAction(TEXT("RightMouseSkill"), EInputEvent::IE_Released, this, &ABaseCharacter::BasicAttackReleased);
	PlayerInputComponent->BindAction(TEXT("ShowSkillTreeUI"), EInputEvent::IE_Released, this, &ABaseCharacter::BasicAttackReleased);
	PlayerInputComponent->BindAction(TEXT("GetItem"), EInputEvent::IE_Released, this, &ABaseCharacter::BasicAttackReleased);
	PlayerInputComponent->BindAction(TEXT("HotBar1"), EInputEvent::IE_Released, this, &ABaseCharacter::BasicAttackReleased);
	PlayerInputComponent->BindAction(TEXT("HotBar2"), EInputEvent::IE_Released, this, &ABaseCharacter::BasicAttackReleased);
	PlayerInputComponent->BindAction(TEXT("HotBar3"), EInputEvent::IE_Released, this, &ABaseCharacter::BasicAttackReleased);
	PlayerInputComponent->BindAction(TEXT("HotBar4"), EInputEvent::IE_Released, this, &ABaseCharacter::BasicAttackReleased);
	PlayerInputComponent->BindAction(TEXT("ShowInventory"), EInputEvent::IE_Released, this, &ABaseCharacter::BasicAttackReleased);
}

void ABaseCharacter::BasicAttack_1()
{
}

void ABaseCharacter::WhenSkillFinishCustom()
{
}

void ABaseCharacter::_1SkillExecute()
{
}

void ABaseCharacter::_2SkillExecute()
{
}

void ABaseCharacter::_3SkillExecute()
{
}

void ABaseCharacter::_4SkillExecute()
{
}

void ABaseCharacter::_5SkillExecute()
{
}

void ABaseCharacter::_6SkillExecute()
{
}

void ABaseCharacter::_7SkillExecute()
{
}

FVector ABaseCharacter::DecalLocation(float MaxLength)
{
	TArray<AActor*> ActorToIgnore;
	FHitResult OutHit;

	if (UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(), SpringArm->GetComponentLocation(),
		SpringArm->GetComponentLocation() + UKismetMathLibrary::GetForwardVector(GetControlRotation())*100000.f, TraceObjectTypeForDecal, false,
		ActorToIgnore, EDrawDebugTrace::None, OutHit, true))
	{
		if ((GetActorLocation() - OutHit.Location).Size() < MaxLength)
		{
			DecalLocationInMaxLength = OutHit.Location;
			return DecalLocationInMaxLength;
		}
		else
		{
			return DecalLocationInMaxLength;
		}
	}
	else
	{
		return DecalLocationInMaxLength;
	}


	return FVector();
}



void ABaseCharacter::InterruptProcess()
{
	if (!IsDead) 
	{
		if (SkillComponent->SkillInterruptable)
		{
			if (!SkillComponent->CantInterruptabelMode)
			{
				AnimInstance->StopAllMontages(0.f);
				AnimInstance->Montage_Play(InterruptMontage);
				SkillComponent->GetInterrupted();
				WhenSkillFinishCustom();
				ProcessReleaseKeyWhenInterruptedDelegate.Broadcast();
			}
		}
	}
}

void ABaseCharacter::GetDamaged(float Damage)
{
	if (!IsDead)
	{
		StatComponent->DecreaseHP(Damage);
		if (Damage != 0.f)
		{
			InterruptProcess();
		}
	}
}

void ABaseCharacter::BasicAttackPressed()
{
	if (!ShowInventoryUI)
	{
		if (!ShowSkillUI)
		{
			if (!IsDead)
			{
				LeftMouseSkillPressedDelegate.Broadcast();
			}
		}
	}
}

void ABaseCharacter::QSkillPressed()
{
	if (!IsDead)
	{
		QSkillPressedDelegate.Broadcast();
	}
}

void ABaseCharacter::ESkillPressed()
{
	if (!IsDead)
	{
		ESkillPressedDelegate.Broadcast();
	}
}

void ABaseCharacter::RSkillPressed()
{
	if (!IsDead)
	{
		RSkillPressedDelegate.Broadcast();
	}
}

void ABaseCharacter::ShiftSkillPressed()
{
	if (!IsDead)
	{
		ShiftSkillPressedDelegate.Broadcast();
	}
}

void ABaseCharacter::RightMouseSkillPressed()
{
	if (!IsDead)
	{
		RightMouseSkillPressedDelegate.Broadcast();
	}
}

void ABaseCharacter::HotBar1Pressed()
{
	if (!IsDead)
	{
		HotBar1PressedDelegate.Broadcast();
	}
}

void ABaseCharacter::HotBar2Pressed()
{
	if (!IsDead)
	{
		HotBar2PressedDelegate.Broadcast();
	}
}

void ABaseCharacter::HotBar3Pressed()
{
	if (!IsDead)
	{
		HotBar3PressedDelegate.Broadcast();
	}
}

void ABaseCharacter::HotBar4Pressed()
{
	if (!IsDead)
	{
		HotBar4PressedDelegate.Broadcast();
	}
}

void ABaseCharacter::GetItemPressed()
{
	if (!IsDead)
	{
		GetItem();
	}
}

void ABaseCharacter::BasicAttackReleased()
{
	if (!ShowInventoryUI)
	{
		if (!ShowSkillUI)
		{
			if (!IsDead)
			{
				LeftMouseSkillReleasedDelegate.Broadcast();
			}
		}
	}
}

void ABaseCharacter::QSkillReleased()
{
	if (!IsDead)
	{
		QSkillReleasedDelegate.Broadcast();
	}
}

void ABaseCharacter::ESkillReleased()
{
	if (!IsDead)
	{
		ESkillReleasedDelegate.Broadcast();
	}
}

void ABaseCharacter::RSkillReleased()
{
	if (!IsDead)
	{
		RSkillReleasedDelegate.Broadcast();
	}
}

void ABaseCharacter::ShiftSkillReleased()
{
	if (!IsDead)
	{
		ShiftSkillReleasedDelegate.Broadcast();
	}
}

void ABaseCharacter::RightMouseSkillReleased()
{
	if (!IsDead)
	{
		RightMouseSkillReleasedDelegate.Broadcast();
	}
}

void ABaseCharacter::MoveForward(float AxisValue)
{
	if (!IsDead)
	{
		if (CanMove)
		{
			FVector ForwardVector = UKismetMathLibrary::GetForwardVector(FRotator(0.f, 0.f, GetController()->GetControlRotation().Yaw));
			AddMovementInput(ForwardVector, AxisValue);
		}
	}
}

void ABaseCharacter::MoveRight(float AxisValue)
{
	if (!IsDead)
	{
		if (CanMove)
		{
			FVector RightVector = UKismetMathLibrary::GetRightVector(FRotator(0.f, 0.f, GetController()->GetControlRotation().Yaw));
			AddMovementInput(RightVector, AxisValue);
		}
	}
}

void ABaseCharacter::LookUp(float AxisValue)
{
	if (!IsDead) 
	{
		AddControllerPitchInput(AxisValue);
	}
}

void ABaseCharacter::LookRight(float AxisValue)
{
	if (!IsDead)
	{
		AddControllerYawInput(AxisValue);
	}
}

void ABaseCharacter::ChangeToNonCombatMovement()
{
	if (!IsDead)
	{
		bUseControllerRotationYaw = false;
		CombatMode = false;
		GetCharacterMovement()->bOrientRotationToMovement = true;
	}
}

void ABaseCharacter::ChangeToCombatMovement()
{
	if (!IsDead)
	{
		CombatMode = true;
		ActorRotationWhenChangeToCombatMode = FRotator(0.f, 0.f, GetActorRotation().Yaw);
		ControlRotationWhenChangeToCombatMode = FRotator(0.f, 0.f, GetControlRotation().Yaw);
		GetCharacterMovement()->bOrientRotationToMovement = false;
	}
}

void ABaseCharacter::Die()
{
	IsDead = true;
	AnimInstance->Montage_Play(DieMontage);

	FTimerHandle GotoMenutimerHandle;
	GetWorld()->GetTimerManager().SetTimer(GotoMenutimerHandle, this, &ABaseCharacter::GoToMenu, 7.f, false);
}

void ABaseCharacter::GetItem()
{
	if (!IsDead)
	{
		ItemDistance = 10000000.f;
		ItemClosest = -1;
		
		TArray<AActor*> ActorToIgnore;
		TArray<AActor*> OutActors;
		if (UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GetActorLocation(), 200.f, ItemObjectType, AItem::StaticClass(), ActorToIgnore, OutActors))
		{
			for (int i=0; i<OutActors.Num(); i++)
			{
				auto OverlapActors = OutActors[i];
				AItem *Item = Cast<AItem>(OverlapActors);
				if (IsValid(Item))
				{
					FHitResult OutHit;
					FCollisionQueryParams Params;
					if (Item->Sphere->LineTraceComponent(OutHit, SpringArm->GetComponentLocation(),
						SpringArm->GetComponentLocation() + UKismetMathLibrary::GetForwardVector(GetControlRotation())*1000.f, Params))
					{
						ItemClosest = i;
					}
				}
			}
			if (ItemClosest == -1)
			{
				for (int i = 0; i < OutActors.Num(); i++)
				{
					if ((OutActors[i]->GetActorLocation() - GetActorLocation()).Size() < ItemDistance)
					{
						ItemDistance = (OutActors[i]->GetActorLocation() - GetActorLocation()).Size();
						ItemClosest = i;
					}
				}
				AItem *ClosestItem = Cast<AItem>(OutActors[ItemClosest]);
				InventoryComponent->GettedItemNum = ClosestItem->ItemNumber;
				InventoryComponent->ItemToInventory();
				ClosestItem->Destroy();
			}
			else
			{
				AItem *ClosestItem = Cast<AItem>(OutActors[ItemClosest]);
				InventoryComponent->GettedItemNum = ClosestItem->ItemNumber;
				InventoryComponent->ItemToInventory();
				ClosestItem->Destroy();
			}
		}

	}
}

/*모든 스킬 시작할 때 이 함수를 호출.(BasicSkill제외) 스킬시작관련 변수 조정*/
void ABaseCharacter::WhenSomethingAttackStart()
{
	if (!IsDead)
	{
		IsAttackForCharRotation = true;
		CanBasicAttack = false;
	}
}

/*모든 스킬 끝날 때 이 함수를 호출.(BasicSkill제외) 스킬 관련 변수 초기화*/
void ABaseCharacter::WhenSomethingAttackFinish()
{
	if (!IsDead)
	{
		IsAttackForCharRotation =false;
		CanBasicAttack = true;
		CanMove = true;
		ReleaseFunctionNeed = false;
		ShowDecal = false;
	}
}

void ABaseCharacter::GoToMenu()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("StartMap")));
}

