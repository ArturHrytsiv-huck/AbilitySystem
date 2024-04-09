// Copyright Artur Hrytsiv


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AS_GameplayTags.h"
#include "AbilitySystem/AS_AttributeSet.h"

void UAttributeMenuWidgetController::BindCallbackToDependencies()
{
	
}

void UAttributeMenuWidgetController::BroadcastInitialsValues()
{
	UAS_AttributeSet* AS = CastChecked<UAS_AttributeSet>(AttributeSet);

	check(AttributeInfo);

	FAS_AttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(FAS_GameplayTags::Get().Attributes_Primary_Strength);
	Info.AttributeValue = AS->GetStrength();
	AttributeInfoDelegate.Broadcast(Info);
}
