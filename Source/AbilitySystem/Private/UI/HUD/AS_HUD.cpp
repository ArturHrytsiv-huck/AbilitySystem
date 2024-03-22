// Copyright Artur Hrytsiv


#include "UI/HUD/AS_HUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/AS_UserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"


AAS_HUD::AAS_HUD()
{
	PrimaryActorTick.bCanEverTick = false;
}



UOverlayWidgetController* AAS_HUD::GetOverlayWidgetController(const FWidgetControllerParams& WidgetControllerParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerPrams(WidgetControllerParams);
		OverlayWidgetController->BindCallbackToDependencies();
	}
	return  OverlayWidgetController;
}

void AAS_HUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay wisget class uinitilized"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay widget controller class uninitilized"))
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAS_UserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParameters(PC, PS, ASC, AS);
	UOverlayWidgetController* NewWidgetController = GetOverlayWidgetController(WidgetControllerParameters);
	OverlayWidget->SetWidgetController(NewWidgetController);
	
	NewWidgetController->BroadcastInitialsValues();
	
	Widget->AddToViewport();

	
}
