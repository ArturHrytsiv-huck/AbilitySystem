// Copyright Artur Hrytsiv


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AS_AttributeSet.h"

void UOverlayWidgetController::BroadcastInitialsValues()
{
	const UAS_AttributeSet* CharacterAttributeSet = Cast<UAS_AttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(CharacterAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(CharacterAttributeSet->GetMaxHealth());
	
	OnManaChanged.Broadcast(CharacterAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(CharacterAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbackToDependencies()
{
	const UAS_AttributeSet* CharacterAttributeSet = Cast<UAS_AttributeSet>(AttributeSet);
	
	//~ Health
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CharacterAttributeSet->GetHealthAttribute())
	.AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CharacterAttributeSet->GetMaxHealthAttribute())
	.AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	//~ End Health
	
	//~ Mana
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CharacterAttributeSet->GetManaAttribute())
	.AddUObject(this, &UOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CharacterAttributeSet->GetMaxManaAttribute())
	.AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
	//~ End Mana
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
