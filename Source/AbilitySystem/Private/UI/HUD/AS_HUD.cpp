// Copyright Artur Hrytsiv


#include "UI/HUD/AS_HUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/AS_UserWidget.h"


AAS_HUD::AAS_HUD()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAS_HUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
