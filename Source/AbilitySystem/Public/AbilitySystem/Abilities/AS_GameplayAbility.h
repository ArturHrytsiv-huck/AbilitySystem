// Copyright Artur Hrytsiv

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AS_GameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM_API UAS_GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	FGameplayTag StartupInputTag;
};
