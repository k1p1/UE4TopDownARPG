// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageTrap.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Characters/TopDownARPGCharacter.h"
#include "TopDownARPG.h"

ADamageTrap::ADamageTrap()
{	
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	SphereComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	RootComponent = SphereComponent;

	SphereComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &ADamageTrap::OnOverlap);
	
	OnOverlapParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComponent"));
	OnOverlapParticle->bAutoActivate = false;
}

void ADamageTrap::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTopDownARPG, Display, TEXT("ADamageTrap::Overlap"));

	OnOverlapParticle->ActivateSystem();

	ATopDownARPGCharacter* Character = Cast<ATopDownARPGCharacter>(Other);
	if (IsValid(Character))
	{
		Character->TakeDamage(Damage, FDamageEvent(UDamageType::StaticClass()), nullptr, this);
	}
}

