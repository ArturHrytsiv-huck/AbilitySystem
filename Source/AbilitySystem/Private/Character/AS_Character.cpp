// Copyright Artur Hrytsiv


#include "Character/AS_Character.h"


// Sets default values
AAS_Character::AAS_Character()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAS_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AAS_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

