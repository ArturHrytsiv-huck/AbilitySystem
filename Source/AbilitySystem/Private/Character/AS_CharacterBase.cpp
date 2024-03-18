// Copyright Artur Hrytsiv


#include "Character/AS_CharacterBase.h"

AAS_CharacterBase::AAS_CharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AAS_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}
