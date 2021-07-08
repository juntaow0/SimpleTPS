// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ClearBBValues.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTTask_ClearBBValues::UBTTask_ClearBBValues() 
{
    NodeName = TEXT("Clear Blackboard Value");
}

EBTNodeResult::Type UBTTask_ClearBBValues::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
    Super::ExecuteTask(OwnerComp,NodeMemory);
    OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    return EBTNodeResult::Succeeded;
}
