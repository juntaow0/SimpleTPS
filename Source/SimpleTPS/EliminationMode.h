// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleTPSGameModeBase.h"
#include "EliminationMode.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLETPS_API AEliminationMode : public ASimpleTPSGameModeBase
{
	GENERATED_BODY()
public:
	virtual void PawnKilled(APawn* PawnKilled) override;
	
};
