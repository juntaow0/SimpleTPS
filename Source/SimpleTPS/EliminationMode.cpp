// Fill out your copyright notice in the Description page of Project Settings.


#include "EliminationMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AEliminationMode::PawnKilled(APawn* PawnKilled) 
{
    Super::PawnKilled(PawnKilled);

    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController){
        EndGame(false);
        return; 
    }
    for (auto Controller:TActorRange<AShooterAIController>(GetWorld())){
        if (!Controller->IsDead()) return;
    }
    EndGame(true); 
}

void AEliminationMode::EndGame(bool bIsPlayerWon) 
{
    for (auto Controller:TActorRange<AController>(GetWorld())){
        bool bIsWinner = Controller->IsPlayerController()==bIsPlayerWon;
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }
}
