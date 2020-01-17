// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability.h"
#include "TopDownARPG.h"

bool UAbility::Activate(FVector AimLocation)
{
	if (bIsOffCooldown == false)
	{
		return false;
	}

    UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		UE_LOG(LogTopDownARPG, Error, TEXT("UAbility::Activate IsValid(World) == false"));
		return false;
	}
	
    TimerManager = &World->GetTimerManager();
    TimerManager->SetTimer(CooldownTimerHandle, this, &UAbility::OnCooldownTimerExpired, CooldownTime);
    bIsOffCooldown = false;

	AActor* Owner = Cast<AActor>(GetOuter());
	if (IsValid(Owner) == false)
	{
		UE_LOG(LogTopDownARPG, Error, TEXT("UAbility::Activate IsValid(Owner) == false"));
		return false;
	}

    OnActivateBlueprint(Owner);
	return true;
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