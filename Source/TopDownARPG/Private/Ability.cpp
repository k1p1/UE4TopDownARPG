// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability.h"

void UAbility::Activate(AActor* Source)
{
    UWorld* World = Source->GetWorld();
    check(World);
    TimerManager = &World->GetTimerManager();
    TimerManager->SetTimer(CooldownTimerHandle, this, &UAbility::OnCooldownTimerExpired, CooldownTimeDilation, true, CooldownTime);
    bIsOffCooldown = false;

    OnActivateBlueprint(Source);
}

void UAbility::OnCooldownTimerExpired()
{
    bIsOffCooldown = true;
}

void UAbility::BeginDestroy()
{
	if (TimerManager)
	{
		TimerManager->ClearTimer(CooldownTimerHandle);
		TimerManager = nullptr;
	}
    Super::BeginDestroy();
}