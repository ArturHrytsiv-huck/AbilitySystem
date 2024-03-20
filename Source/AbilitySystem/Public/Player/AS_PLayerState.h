// Copyright Artur Hrytsiv

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
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditAnywhere, Category = "")
	TObjectPtr<UAttributeSet> AttributeSet;
public:
};
