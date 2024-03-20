// Copyright Artur Hrytsiv


#include "AbilitySystem/AS_AttributeSet.h"
#include "Net/UnrealNetwork.h"

UAS_AttributeSet::UAS_AttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(Health.GetCurrentValue());
	
	InitMana(100.f);
	InitMaxMana(Mana.GetCurrentValue());
}

void UAS_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	//~ Health
	DOREPLIFETIME_CONDITION_NOTIFY(UAS_AttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAS_AttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	
	//~ Mana
	DOREPLIFETIME_CONDITION_NOTIFY(UAS_AttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAS_AttributeSet, MaxMana, COND_None, REPNOTIFY_Always);

	//~ Mana
}

void UAS_AttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAS_AttributeSet, Health, OldHealth);
}

void UAS_AttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAS_AttributeSet, MaxHealth, OldMaxHealth);
}

void UAS_AttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAS_AttributeSet, Mana, OldMana);
}

void UAS_AttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAS_AttributeSet, MaxMana, OldMaxMana);
}
