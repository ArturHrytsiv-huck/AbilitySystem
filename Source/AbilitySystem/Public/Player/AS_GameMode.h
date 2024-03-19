// Copyright Artur Hrytsiv

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "AS_GameMode.generated.h"

UCLASS()
class ABILITYSYSTEM_API AAS_GameMode : public AGameMode
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAS_GameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
