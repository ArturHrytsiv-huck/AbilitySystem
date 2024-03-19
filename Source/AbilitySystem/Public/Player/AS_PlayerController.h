// Copyright Artur Hrytsiv

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AS_PlayerController.generated.h"


class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class ABILITYSYSTEM_API AAS_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAS_PlayerController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	void Move(const FInputActionValue& InputActionValue);
private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> CharacterContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;
};
