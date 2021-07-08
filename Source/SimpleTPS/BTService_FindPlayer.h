// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_FindPlayer.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLETPS_API UBTService_FindPlayer : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService_FindPlayer();
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
