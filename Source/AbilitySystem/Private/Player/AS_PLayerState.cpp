// Copyright Artur Hrytsiv


#include "Player/AS_PLayerState.h"

#include "AbilitySystem/AS_AbilitySystemComponent.h"
#include "AbilitySystem/AS_AttributeSet.h"
#include "Net/UnrealNetwork.h"


AAS_PLayerState::AAS_PLayerState()
{
	NetUpdateFrequency = 100.f;
	
	AbilitySystemComponent = CreateDefaultSubobject<UAS_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UAS_AttributeSet>("AttributeSet");
}


UAbilitySystemComponent* AAS_PLayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAS_PLayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AAS_PLayerState, Level);
}

void AAS_PLayerState::OnRep_Level(int32 OldLevel)
{
	
}
