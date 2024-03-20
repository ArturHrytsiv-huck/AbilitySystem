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
	void InitAbilityActorInfo();

	virtual void Tick(float DeltaTime) override;
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
protected:
	virtual void BeginPlay() override;
	
};
