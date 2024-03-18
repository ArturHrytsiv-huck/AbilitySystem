// Copyright Artur Hrytsiv

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AS_CharacterBase.generated.h"

UCLASS(Abstract)
class ABILITYSYSTEM_API AAS_CharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAS_CharacterBase();

protected:
	virtual void BeginPlay() override;

};
