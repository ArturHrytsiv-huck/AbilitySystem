﻿// Copyright Artur Hrytsiv

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "AS_PLayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
UCLASS()
class ABILITYSYSTEM_API AAS_PLayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAS_PLayerState();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

	FORCEINLINE int32 GetPlayerLevel() const { return Level; }
protected:

	UPROPERTY(EditAnywhere, Category = "")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditAnywhere, Category = "")
	TObjectPtr<UAttributeSet> AttributeSet;
private:

	UPROPERTY(VisibleAnywhere, ReplicatedUsing=OnRep_Level)
	int32 Level = 1;

	UFUNCTION()
	void OnRep_Level(int32 OldLevel);
};
