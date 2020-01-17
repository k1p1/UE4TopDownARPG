// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageTrap.generated.h"

UCLASS()
class TOPDOWNARPG_API ADamageTrap : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	float Damage;

public:	
	ADamageTrap();

protected:
	UPROPERTY(VisibleAnywhere, Category = Gameplay)
	class USphereComponent* SphereComponent;

	UPROPERTY(VisibleAnywhere, Category = Visual)
	class UParticleSystemComponent* OnOverlapParticle;

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
