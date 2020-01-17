// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/TopDownARPGCharacter.h"
#include "TopDownARPG.h"

AEnemyAIController::AEnemyAIController()
{
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard"));
	BehaviourTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviourTree"));
}

void AEnemyAIController::OnPossess(APawn* Pawn)
{
	Super::OnPossess(Pawn);

	if (IsValid(BehaviourTree))
	{
		BlackboardComponent->InitializeBlackboard(*BehaviourTree->BlackboardAsset);
		BehaviourTreeComponent->StartTree(*BehaviourTree);
	}
}

void AEnemyAIController::ActivateAbility(FVector AimLocation)
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
		Ability->Activate(AimLocation);
	}
}
