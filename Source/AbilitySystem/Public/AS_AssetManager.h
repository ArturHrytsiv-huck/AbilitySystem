// Copyright Artur Hrytsiv

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "AS_AssetManager.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM_API UAS_AssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	static UAS_AssetManager& Get();
	
protected:
	virtual void StartInitialLoading() override;
};
