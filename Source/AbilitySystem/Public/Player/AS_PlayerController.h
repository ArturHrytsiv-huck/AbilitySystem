// Copyright Artur Hrytsiv

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Input/AS_InputConfig.h"
#include "GameFramework/PlayerController.h"
#include "AS_PlayerController.generated.h"


class USplineComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;
class UAS_AbilitySystemComponent;

UCLASS()
class ABILITYSYSTEM_API AAS_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAS_PlayerController();

	virtual void PlayerTick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();
private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> CharacterContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;

	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UAS_InputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<UAS_AbilitySystemComponent> ASAbilitySystemComponent;

	UAS_AbilitySystemComponent* GetASC();

	//~ Movement
	FVector CachedDestination = FVector::ZeroVector;
	float FollowTime = 0.f;
	float ShortPressThreshold = 0.5f;
	bool bAutoRunning = false;
	bool bTargeting = false;
	
	UPROPERTY(EditDefaultsOnly)
	float AutoRunAcceptanceRadius = 50.f;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> Spline;
};
