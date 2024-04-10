// Copyright Artur Hrytsiv


#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "AbilitySystem/AS_AttributeSet.h"


void UAttributeMenuWidgetController::BindCallbackToDependencies()
{
	UAS_AttributeSet* AS = CastChecked<UAS_AttributeSet>(AttributeSet);
	for (auto& Pair : AS->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
	[this, Pair](const FOnAttributeChangeData& Data)
		{
			BroadcastAttributeInfo(Pair.Key, Pair.Value());
		});
	}

}

void UAttributeMenuWidgetController::BroadcastInitialsValues()
{
	UAS_AttributeSet* AS = CastChecked<UAS_AttributeSet>(AttributeSet);

	check(AttributeInfo);

	for (auto& Pair : AS->TagsToAttributes)
	{
		BroadcastAttributeInfo(Pair.Key, Pair.Value());
	}
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag, const FGameplayAttribute& Attribute) const
{
	FAS_AttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}
