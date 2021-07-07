// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacterBase.h"
#include "GunBase.h"

// Sets default values
AShooterCharacterBase::AShooterCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
	Gun = GetWorld()->SpawnActor<AGunBase>(GunBaseClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"),EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(),FAttachmentTransformRules::KeepRelativeTransform,TEXT("WeaponSocket"));
	Gun->SetOwner(this);
}

// Called every frame
void AShooterCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AShooterCharacterBase::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AShooterCharacterBase::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AShooterCharacterBase::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &AShooterCharacterBase::LookRight);
	PlayerInputComponent->BindAction(TEXT("Jump"),EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AShooterCharacterBase::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("LookRightRate"), this, &AShooterCharacterBase::LookRightRate);

	PlayerInputComponent->BindAction(TEXT("Fire"),EInputEvent::IE_Pressed, this, &AShooterCharacterBase::FireWeapon);
	PlayerInputComponent->BindAction(TEXT("SecondaryFunction"),EInputEvent::IE_Pressed, this, &AShooterCharacterBase::UseSecondaryFunction);
}

float AShooterCharacterBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) 
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	if (DamageToApply==0 || Health<=0){
		return 0;
	}
	Health=FMath::Clamp(Health-DamageToApply, 0.0f,MaxHealth);
	UE_LOG(LogTemp, Warning, TEXT("Health: %f"),Health);
	if (Health<=0){
		UE_LOG(LogTemp, Warning, TEXT("Actor died"));
	}
	return DamageToApply;
}

void AShooterCharacterBase::MoveForward(float AxisValue) 
{
	AddMovementInput(GetActorForwardVector()*AxisValue);
}

void AShooterCharacterBase::MoveRight(float AxisValue) 
{
	AddMovementInput(GetActorRightVector()*AxisValue);
}

void AShooterCharacterBase::LookUp(float AxisValue) 
{
	AddControllerPitchInput(AxisValue);
}

void AShooterCharacterBase::LookRight(float AxisValue) 
{
	AddControllerYawInput(AxisValue);
}

void AShooterCharacterBase::LookUpRate(float AxisValue) 
{
	AddControllerPitchInput(AxisValue*GetWorld()->DeltaTimeSeconds*RotationRate);
}

void AShooterCharacterBase::LookRightRate(float AxisValue) 
{
	AddControllerYawInput(AxisValue*GetWorld()->DeltaTimeSeconds*RotationRate);
}

void AShooterCharacterBase::FireWeapon() 
{
	if (!Gun){
		return;
	}
	Gun->Fire();
}

void AShooterCharacterBase::UseSecondaryFunction() 
{
	if (!Gun){
		return;
	}
	Gun->SecondaryFunction();
}

