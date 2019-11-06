// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WinTrigger.generated.h"

UCLASS()
class TOPDOWNARPG_API AWinTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	AWinTrigger();

protected:
	UPROPERTY(VisibleAnywhere, Category = Gameplay)
	class USphereComponent* SphereComponent;

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};
