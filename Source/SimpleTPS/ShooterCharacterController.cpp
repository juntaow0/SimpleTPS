// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacterController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterCharacterController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner) 
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);
    if (HUD){
        HUD->RemoveFromViewport();
    }
    if (bIsWinner){
        UUserWidget* WinScreen = CreateWidget(this,WinScreenClass);
        if (WinScreen){
            WinScreen->AddToViewport();
        }
    }else{
        UUserWidget* LoseScreen = CreateWidget(this,LoseScreenClass);
        if (LoseScreen){
            LoseScreen->AddToViewport();
        }
    }
    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}

void AShooterCharacterController::BeginPlay() 
{
    Super::BeginPlay();
    HUD = CreateWidget(this,HUDClass);
    if (HUD){
        HUD->AddToViewport();
    }
}
