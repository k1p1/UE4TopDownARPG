// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNARPG_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

	AEnemyAIController();
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* BehaviourTree;

	UPROPERTY()
	class UBlackboardComponent* BlackboardComponent;

	UPROPERTY()
	class UBehaviorTreeComponent* BehaviourTreeComponent;

public:
	void ActivateAbility(FVector AimLocation);
};
