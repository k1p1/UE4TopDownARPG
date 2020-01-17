// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TopDownARPGPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Engine/World.h"
#include "Characters/TopDownARPGCharacter.h"
#include "TopDownARPG.h"


ATopDownARPGPlayerController::ATopDownARPGPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ATopDownARPGPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}

void ATopDownARPGPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ATopDownARPGPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &ATopDownARPGPlayerController::OnSetDestinationReleased);

	InputComponent->BindAction("Ability1", IE_Pressed, this, &ATopDownARPGPlayerController::ActivateAbility1);
	InputComponent->BindAction("Ability2", IE_Pressed, this, &ATopDownARPGPlayerController::ActivateAbility2);
}

void ATopDownARPGPlayerController::ActivateAbility1()
{
	ATopDownARPGCharacter* PlayerCharacter = Cast<ATopDownARPGCharacter>(GetPawn());
	if (IsValid(PlayerCharacter) == false)
	{
		UE_LOG(LogTopDownARPG, Error, TEXT("ATopDownARPGPlayerController::ActivateAbility1 IsValid(PlayerCharacter) == false"));
		return;
	}

	UAbility* Ability = PlayerCharacter->AbilityInstances[0];
	if (IsValid(Ability))
	{
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{
			Ability->Activate(Hit.ImpactPoint);
		}
	}
}

void ATopDownARPGPlayerController::ActivateAbility2()
{
	ATopDownARPGCharacter* PlayerCharacter = Cast<ATopDownARPGCharacter>(GetPawn());
	if (IsValid(PlayerCharacter) == false)
	{
		UE_LOG(LogTopDownARPG, Error, TEXT("ATopDownARPGPlayerController::ActivateAbility1 IsValid(PlayerCharacter) == false"));
		return;
	}

	UAbility* Ability = PlayerCharacter->AbilityInstances[1];
	if (IsValid(Ability))
	{
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{
			Ability->Activate(Hit.ImpactPoint);
		}
	}
}

void ATopDownARPGPlayerController::MoveToMouseCursor()
{
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(Hit.ImpactPoint);
	}
}

void ATopDownARPGPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void ATopDownARPGPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void ATopDownARPGPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void ATopDownARPGPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}
