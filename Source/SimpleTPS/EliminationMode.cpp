// Fill out your copyright notice in the Description page of Project Settings.


#include "EliminationMode.h"


void AEliminationMode::PawnKilled(APawn* PawnKilled) 
{
    Super::PawnKilled(PawnKilled);

    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController){
        PlayerController->GameHasEnded(nullptr, false);
    }else{

    }
}
