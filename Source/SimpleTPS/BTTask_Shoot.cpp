// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "AIController.h"
#include "ShooterCharacterBase.h"


UBTTask_Shoot::UBTTask_Shoot() 
{
    NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
    Super::ExecuteTask(OwnerComp,NodeMemory);
    if (!OwnerComp.GetAIOwner()){
        return EBTNodeResult::Failed;
    }
    auto Actor = Cast<AShooterCharacterBase>(OwnerComp.GetAIOwner()->GetPawn());
    if (!Actor){
        return EBTNodeResult::Failed;
    }
    Actor->FireWeapon();
    return EBTNodeResult::Succeeded;
}


