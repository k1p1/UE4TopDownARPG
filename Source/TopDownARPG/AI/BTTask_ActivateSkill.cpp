// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ActivateSkill.h"
#include "Controllers/EnemyAIController.h"

EBTNodeResult::Type UBTTask_ActivateSkill::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(OwnerComp.GetOwner());
	if (IsValid(EnemyAIController))
	{
		EnemyAIController->ActivateAbility();
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
