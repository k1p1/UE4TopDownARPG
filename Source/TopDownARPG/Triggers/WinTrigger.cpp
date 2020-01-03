// Fill out your copyright notice in the Description page of Project Settings.


#include "WinTrigger.h"
#include "Components/SphereComponent.h"
#include "GameModes/TopDownARPGGameMode.h"

AWinTrigger::AWinTrigger()
{
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	SphereComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	RootComponent = SphereComponent;

	SphereComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &AWinTrigger::OnOverlap);
}

void AWinTrigger::OnOverlap(UPrimitiveComponent * OverlappedComp, AActor * Other, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ATopDownARPGGameMode* GameMode = Cast<ATopDownARPGGameMode>(GetWorld()->GetAuthGameMode());
	if (IsValid(GameMode))
	{
		GameMode->EndGame(true);
	}
}
