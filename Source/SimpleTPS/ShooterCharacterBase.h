// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacterBase.generated.h"

class AGunBase;

UCLASS()
class SIMPLETPS_API AShooterCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacterBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure)
	bool IsDead() const;

	UFUNCTION(BlueprintCallable)
	void FireWeapon();

	UFUNCTION(BlueprintPure)
	float GetHealthPercentage();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);	
	void LookUp(float AxisValue);
	void LookRight(float AxisValue);
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);
	
	void UseSecondaryFunction();

	UPROPERTY(EditAnywhere)
	float RotationRate = 20;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere)
	float Health = 0.f;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGunBase> GunBaseClass;

	UPROPERTY()
	AGunBase* Gun = nullptr;

	UPROPERTY(VisibleAnywhere)
	bool IsAlive = true;
};
