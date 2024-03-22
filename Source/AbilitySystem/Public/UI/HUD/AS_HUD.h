// Copyright Artur Hrytsiv

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AS_HUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
struct FWidgetControllerParams;
class UOverlayWidgetController;
class UAS_UserWidget;


UCLASS()
class ABILITYSYSTEM_API AAS_HUD : public AHUD
{
	GENERATED_BODY()

public:
	AAS_HUD();

public:
	UPROPERTY()
	TObjectPtr<UAS_UserWidget> OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WidgetControllerParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAS_UserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
