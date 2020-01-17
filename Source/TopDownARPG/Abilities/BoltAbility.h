// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Ability.h"
#include "BoltAbility.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNARPG_API UBoltAbility : public UAbility
{
	GENERATED_BODY()

public:
	virtual bool Activate(FVector AimLocation) override;

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AProjectile> ProjectileClass;
	
};
