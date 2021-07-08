// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_ClearBBValues.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLETPS_API UBTTask_ClearBBValues : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_ClearBBValues();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	
};
