// Copyright Artur Hrytsiv


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AS_AbilitySystemComponent.h"
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
	.AddLambda([this](const FOnAttributeChangeData& Data)
	{
		OnHealthChanged.Broadcast(Data.NewValue);
	});

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CharacterAttributeSet->GetMaxHealthAttribute())
	.AddLambda([this](const FOnAttributeChangeData& Data)
	{
		OnMaxHealthChanged.Broadcast(Data.NewValue);
	});
	//~ End Health
	
	//~ Mana
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CharacterAttributeSet->GetManaAttribute())
	.AddLambda([this](const FOnAttributeChangeData& Data)
	{
		OnManaChanged.Broadcast(Data.NewValue);
	});

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CharacterAttributeSet->GetMaxManaAttribute())
	.AddLambda([this](const FOnAttributeChangeData& Data)
	{
		OnMaxManaChanged.Broadcast(Data.NewValue);
	});
	//~ End Mana

	//~ Tags Delegate
		Cast<UAS_AbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
			[this](const FGameplayTagContainer& AssetTags)
			{
				for (const FGameplayTag& Tag : AssetTags)
				{
					FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
					if (Tag.MatchesTag(MessageTag))
					{
						const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
						MessageWidgetRowDelegate.Broadcast(*Row);
					}
				}
			});
	//~ Tags Delegate
}
