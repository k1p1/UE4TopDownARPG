// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ActivateSkill.h"
#include "Controllers/EnemyAIController.h"

EBTNodeResult::Type UBTTask_ActivateSkill::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(OwnerComp.GetOwner());
	if (IsValid(EnemyAIController) == false)
	{
		return EBTNodeResult::Failed;
	}
	
	APawn* EnemyPawn = EnemyAIController->GetPawn();
	if (IsValid(EnemyPawn) == false)
	{
		return EBTNodeResult::Failed;
	}

	FVector AimLocation = EnemyPawn->GetActorLocation() + EnemyPawn->GetActorForwardVector() * 100.0f;
	EnemyAIController->ActivateAbility(AimLocation);

	return EBTNodeResult::Succeeded;
}
