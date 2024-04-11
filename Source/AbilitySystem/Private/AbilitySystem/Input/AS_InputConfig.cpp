// Copyright Artur Hrytsiv


#include "AbilitySystem/Input/AS_InputConfig.h"

const UInputAction* UAS_InputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (auto Action : AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find AbilityIputAction for InputTag [%s] on InputConfig [%s]"), *InputTag.ToString(), *GetNameSafe(this));
	}
	return nullptr;
}
