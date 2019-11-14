// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TimerManager.h"
#include "TopDownARPGGameMode.generated.h"

UCLASS(minimalapi)
class ATopDownARPGGameMode : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	float GameTimeInSeconds;

	FTimerHandle LoseTimerHandle;
	FTimerDelegate LoseTimerDelegate;

public:
	ATopDownARPGGameMode();

	void EndGame(bool IsWin);

protected:
	virtual void BeginPlay() override;
};



