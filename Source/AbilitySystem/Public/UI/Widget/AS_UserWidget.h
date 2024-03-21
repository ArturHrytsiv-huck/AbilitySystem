// Copyright Artur Hrytsiv

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AS_UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM_API UAS_UserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
protected:

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
