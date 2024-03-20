// Copyright Artur Hrytsiv


#include "Character/AS_Character.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AS_PLayerState.h"


// Sets default values
AAS_Character::AAS_Character()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AAS_Character::InitAbilityActorInfo()
{
	AAS_PLayerState* ASPLayerState = GetPlayerState<AAS_PLayerState>();
	// check(ASPLayerState);
	ASPLayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(ASPLayerState, this);
	AbilitySystemComponent = ASPLayerState->GetAbilitySystemComponent();
	AttributeSet = ASPLayerState->GetAttributeSet();
}

void AAS_Character::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the Server
	InitAbilityActorInfo();
}

void AAS_Character::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the Client
	InitAbilityActorInfo();
}

void AAS_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

