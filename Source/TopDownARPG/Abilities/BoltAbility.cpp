// Fill out your copyright notice in the Description page of Project Settings.


#include "BoltAbility.h"
#include "Engine/World.h"
#include "Projectiles/Projectile.h"
#include "TopDownARPG.h"

bool UBoltAbility::Activate(FVector AimLocation)
{
	if (Super::Activate(AimLocation) == false)
	{
		return false;
	}

	UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		UE_LOG(LogTopDownARPG, Error, TEXT("UBoltAbility::Activate IsValid(World) == false"));
	}

	AActor* Owner = Cast<AActor>(GetOuter());
	if (IsValid(Owner) == false)
	{
		UE_LOG(LogTopDownARPG, Error, TEXT("UAbility::Activate IsValid(Owner) == false"));
		return false;
	}

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = Owner;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FVector Direction = AimLocation - Owner->GetActorLocation();
	Direction.Z = 0.0f;
	Direction.Normalize();

	FVector SpawnLocation = Owner->GetActorLocation() + Direction * 100.0f;

	AActor* Projectile = World->SpawnActor<AActor>(ProjectileClass, SpawnLocation, Direction.Rotation(), SpawnParameters);
	if (IsValid(Projectile) == false)
	{
		UE_LOG(LogTopDownARPG, Error, TEXT("UBoltAbility::Activate IsValid(Projectile) == false"));
		return false;
	}
	return true;
}