// Fill out your copyright notice in the Description page of Project Settings.


#include "BoltAbility.h"
#include "Projectiles/Projectile.h"
#include "TopDownARPG.h"
#include "Engine/World.h"

void UBoltAbility::Activate(AActor* Source)
{
	Super::Activate(Source);

	UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		UE_LOG(LogTopDownARPG, Error, TEXT("UBoltAbility::Activate IsValid(World) == false"));
	}

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = Source;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FVector SpawnLocation = Source->GetActorLocation() + Source->GetActorForwardVector() * 100.0f;

	AActor* Projectile = World->SpawnActor<AActor>(ProjectileClass, SpawnLocation, Source->GetActorRotation(), SpawnParameters);
	if (IsValid(Projectile) == false)
	{
		UE_LOG(LogTopDownARPG, Error, TEXT("UBoltAbility::Activate IsValid(Projectile) == false"));
		return;
	}
}