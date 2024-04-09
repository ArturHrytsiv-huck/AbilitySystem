// Copyright Artur Hrytsiv

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AS_BlueprintLibrary.generated.h"

class UOverlayWidgetController;
/**
 * 
 */
UCLASS()
class ABILITYSYSTEM_API UAS_BlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "AS BlueprintLibrary|Widget")
	static UOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);
	
	UFUNCTION(BlueprintPure, Category = "AS BlueprintLibrary|Widget")
	static UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const UObject* WorldContextObject);
};
