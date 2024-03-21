// Copyright Artur Hrytsiv

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AS_HUD.generated.h"

class UAS_UserWidget;


UCLASS()
class ABILITYSYSTEM_API AAS_HUD : public AHUD
{
	GENERATED_BODY()

public:
	AAS_HUD();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY()
	TObjectPtr<UAS_UserWidget> OverlayWidget;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAS_UserWidget> OverlayWidgetClass;
};
