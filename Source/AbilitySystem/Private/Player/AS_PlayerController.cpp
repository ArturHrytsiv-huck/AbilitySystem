// Copyright Artur Hrytsiv


#include "Player/AS_PlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AS_GameplayTags.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystem/AS_AbilitySystemComponent.h"
#include "AbilitySystem/Input/AS_InputComponent.h"
#include "Components/SplineComponent.h"
#include "Interaction/EnemyInterface.h"

// Sets default values
AAS_PlayerController::AAS_PlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	Spline = CreateDefaultSubobject<USplineComponent>("Spline");
	
}

void AAS_PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}


// Called when the game starts or when spawned
void AAS_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(CharacterContext);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(CharacterContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAS_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UAS_InputComponent* ASInputComponent = CastChecked<UAS_InputComponent>(InputComponent);
	
	ASInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAS_PlayerController::Move);
	ASInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
}

void AAS_PlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AAS_PlayerController::CursorTrace()
{
	FHitResult CursorHit;

	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			ThisActor->HighlightActor();
		}
	}
	else
	{
		if (ThisActor == nullptr)
		{
			LastActor->UnHighlightActor();
		}
		else
		{
			if (LastActor != ThisActor)
			{
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
		}
	}
}

void AAS_PlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
	// bTargeting = ThisActor ? true : false;
	// bAutoRunning = false;
}

void AAS_PlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	if (GetASC() == nullptr) return;
	GetASC()->AbilityInputTagReleased(InputTag);
}

void AAS_PlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
	if (!InputTag.MatchesTagExact(FAS_GameplayTags::Get().InputTag_LMB))
	{
		if (GetASC())
		{
			GetASC()->AbilityInputTagHeld(InputTag);
		}
		return;
	}
	if (bTargeting)
	{
		if (GetASC())
		{
			GetASC()->AbilityInputTagHeld(InputTag);
		}
	}
	else
	{
		FollowTime += GetWorld()->GetDeltaSeconds();

		FHitResult Hit;

		if (GetHitResultUnderCursor(ECC_Visibility, false, Hit))
		{
			CachedDestination = Hit.ImpactPoint;
		}

		if (APawn* ControlledPawn = GetPawn())
		{
			const FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
			ControlledPawn->AddMovementInput(WorldDirection);
		}
	}
	// bTargeting = ThisActor ? true : false;
	// bAutoRunning = false;

	
}

UAS_AbilitySystemComponent* AAS_PlayerController::GetASC()
{
	if (ASAbilitySystemComponent == nullptr)
	{
		ASAbilitySystemComponent = Cast<UAS_AbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}
	return ASAbilitySystemComponent;
}
