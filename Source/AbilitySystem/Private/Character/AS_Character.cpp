// Copyright Artur Hrytsiv


#include "Character/AS_Character.h"

#include "GameFramework/CharacterMovementComponent.h"


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

void AAS_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

