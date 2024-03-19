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
	AAS_Character();

	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	
};
