// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunBase.generated.h"

UCLASS()
class SIMPLETPS_API AGunBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root = nullptr;
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh = nullptr;
	UPROPERTY(EditAnywhere,Category="Effects")
	UParticleSystem* Muzzle = nullptr;
	UPROPERTY(EditAnywhere,Category="Effects")
	UParticleSystem* Decal = nullptr;
	UPROPERTY(EditAnywhere, Category="Weapon Stats")
	float MaxRange = 100000.0f;
	UPROPERTY(EditAnywhere, Category="Weapon Stats")
	float DamageAmount = 34.0f;

	bool Raycast(FHitResult& Hit, FRotator& Rotation);
	AController* GetOwnerController() const;

public:
	void Fire();
	void SecondaryFunction();
};
