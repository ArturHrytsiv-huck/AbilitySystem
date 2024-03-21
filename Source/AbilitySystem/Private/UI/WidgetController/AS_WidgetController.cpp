// Copyright Artur Hrytsiv


#include "UI/WidgetController/AS_WidgetController.h"

void UAS_WidgetController::SetWidgetControllerPrams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
	
}
