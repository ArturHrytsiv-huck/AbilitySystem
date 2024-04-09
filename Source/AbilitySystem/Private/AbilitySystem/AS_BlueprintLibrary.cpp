// Copyright Artur Hrytsiv


#include "AbilitySystem/AS_BlueprintLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "Player/AS_PLayerState.h"
#include "UI/HUD/AS_HUD.h"
#include "UI/WidgetController/AS_WidgetController.h"

UOverlayWidgetController* UAS_BlueprintLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AAS_HUD* AbilitySysHUD = Cast<AAS_HUD>(PC->GetHUD()))
		{
			AAS_PLayerState* PS = PC->GetPlayerState<AAS_PLayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return AbilitySysHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* UAS_BlueprintLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AAS_HUD* AbilitySysHUD = Cast<AAS_HUD>(PC->GetHUD()))
		{
			AAS_PLayerState* PS = PC->GetPlayerState<AAS_PLayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return AbilitySysHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}
