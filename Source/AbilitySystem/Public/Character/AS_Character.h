// Copyright Artur Hrytsiv

#pragma once

#include "CoreMinimal.h"
#include "AS_CharacterBase.h"
#include "GameFramework/Character.h"
#include "AS_Character.generated.h"

UCLASS()
class ABILITYSYSTEM_API AAS_Character : public AAS_CharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAS_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
