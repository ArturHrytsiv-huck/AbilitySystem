// Copyright Artur Hrytsiv


#include "Character/AS_Enemy.h"

#include "AbilitySystem/AbilitySystem.h"
#include "AbilitySystem/AS_AbilitySystemComponent.h"
#include "AbilitySystem/AS_AttributeSet.h"
#include "UI/Widget/AS_UserWidget.h"


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

	HealthBar = CreateDefaultSubobject<UWidgetComponent>("HealthBar");
	HealthBar->SetupAttachment(GetRootComponent());
}

void AAS_Enemy::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();

	if (UAS_UserWidget* ASUserWidget = Cast<UAS_UserWidget>(HealthBar->GetUserWidgetObject()))
	{
		ASUserWidget->SetWidgetController(this);
	}

	if (const UAS_AttributeSet* AS = CastChecked<UAS_AttributeSet>(AttributeSet))
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AS->GetHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnHealthChangedDelegate.Broadcast(Data.NewValue);
		});

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AS->GetMaxHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChangedDelegate.Broadcast(Data.NewValue);
		});
		
		OnHealthChangedDelegate.Broadcast(AS->GetHealth());
		OnMaxHealthChangedDelegate.Broadcast(AS->GetMaxHealth());
	}
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

int32 AAS_Enemy::GetPlayerLevel()
{
	return Level;
}

void AAS_Enemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UAS_AbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
	InitializeDefaultAttributes();
}
