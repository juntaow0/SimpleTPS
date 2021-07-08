// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacterBase.h"

void AShooterAIController::BeginPlay() 
{
    Super::BeginPlay();  
    if (AIBehavior){
        RunBehaviorTree(AIBehavior);
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"),GetPawn()->GetActorLocation());
    }
}

bool AShooterAIController::IsDead() 
{
    auto Actor = Cast<AShooterCharacterBase>(GetPawn());
    if (!Actor){
        return true;
    }
    return Actor->IsDead();
}
