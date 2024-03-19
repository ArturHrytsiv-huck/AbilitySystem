// Copyright Artur Hrytsiv


#include "Player/AS_GameMode.h"


// Sets default values
AAS_GameMode::AAS_GameMode()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAS_GameMode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAS_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

