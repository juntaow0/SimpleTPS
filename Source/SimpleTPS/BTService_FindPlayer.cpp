// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_FindPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"


UBTService_FindPlayer::UBTService_FindPlayer() 
{
    NodeName=TEXT("Find Player Location");
}

void UBTService_FindPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) 
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
    auto Actor = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
    auto AIController = OwnerComp.GetAIOwner();
    if (!Actor || !AIController) return;
    if (AIController->LineOfSightTo(Actor)){
        OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),Actor->GetActorLocation());
    }else{
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    }
}
