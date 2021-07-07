// Fill out your copyright notice in the Description page of Project Settings.


#include "GunBase.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGunBase::AGunBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AGunBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGunBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGunBase::Fire() 
{
	UE_LOG(LogTemp, Warning, TEXT("Fired"));
	UGameplayStatics::SpawnEmitterAttached(Muzzle, Mesh, TEXT("MuzzleFlashSocket"));
	auto OwnerPawn = Cast<APawn>(GetOwner());
	if (!OwnerPawn) return;
	auto OwnerController = OwnerPawn->GetController();
	if (!OwnerController) return;
	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location, Rotation);
	FVector End = Location+Rotation.Vector()*MaxRange;
	FHitResult Hit;
	if(GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1)){
		DrawDebugPoint(GetWorld(), Hit.Location, 20, FColor::Red, true);
	}
}

void AGunBase::SecondaryFunction() 
{
	UE_LOG(LogTemp, Warning, TEXT("Zoom"));
}

