// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability.h"
#include "TopDownARPG.h"

void UAbility::Activate(AActor* Source)
{
    UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		UE_LOG(LogTopDownARPG, Error, TEXT("UAbility::Activate IsValid(World) == false"));
		return;
	}
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