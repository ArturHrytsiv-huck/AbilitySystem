// Copyright Artur Hrytsiv


#include "AS_AssetManager.h"

#include "AbilitySystemGlobals.h"
#include "AS_GameplayTags.h"

UAS_AssetManager& UAS_AssetManager::Get()
{
	check(GEngine);

	UAS_AssetManager* AuraAssetManager = Cast<UAS_AssetManager>(GEngine->AssetManager);
	return *AuraAssetManager;
}

void UAS_AssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FAS_GameplayTags::InitializeNativeGameplayTags();
	
	// Crucial importance for Multiplayer to use Target Data
	UAbilitySystemGlobals::Get().InitGlobalData();
	
}
