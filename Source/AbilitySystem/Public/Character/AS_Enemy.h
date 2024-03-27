// Copyright Artur Hrytsiv

#pragma once

#include "CoreMinimal.h"
#include "AS_CharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AS_Enemy.generated.h"

UCLASS()
class ABILITYSYSTEM_API AAS_Enemy : public AAS_CharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAS_Enemy();

	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;

public:
	
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	virtual void InitAbilityActorInfo() override;
};
