// Copyright Artur Hrytsiv


#include "Character/AS_Enemy.h"

#include "AbilitySystem/AbilitySystem.h"
#include "AbilitySystem/AS_AbilitySystemComponent.h"
#include "AbilitySystem/AS_AttributeSet.h"


AAS_Enemy::AAS_Enemy()
{
	PrimaryActorTick.bCanEverTick = true;
	
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

	AbilitySystemComponent = CreateDefaultSubobject<UAS_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UAS_AttributeSet>("AttributeSet");
	
}

void AAS_Enemy::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AAS_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAS_Enemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	Weapon->SetRenderCustomDepth(true);
}

void AAS_Enemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
