// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Ability.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class UAbility : public UObject
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditAnywhere)
    float CooldownTime = 1.f;

    UFUNCTION(BlueprintCallable)
    virtual bool Activate(FVector AimLocation);

    UFUNCTION(BlueprintImplementableEvent)
    void OnActivateBlueprint(AActor* Source);

    UFUNCTION(BlueprintCallable)
    bool IsOffCooldown() const { return bIsOffCooldown; }

    virtual void BeginDestroy();
private:
    bool bIsOffCooldown = true;
    FTimerManager* TimerManager = nullptr;
    FTimerHandle CooldownTimerHandle;
    void OnCooldownTimerExpired();
};
