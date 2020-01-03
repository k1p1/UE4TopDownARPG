#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "Engine/DataTable.h"
#include "Abilities/Ability.h"
#include "TopDownARPGCharacterStruct.generated.h"

USTRUCT(BlueprintType)
struct FTopDownARPGCharacterStruct : public FTableRowBase
{
	GENERATED_BODY()
		
	UPROPERTY(EditAnywhere)
	float MaximumHealth = 100.0f;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UAbility>> AbilityTemplates;

};