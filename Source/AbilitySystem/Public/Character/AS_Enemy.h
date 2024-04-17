// Copyright Artur Hrytsiv

#pragma once

#include "CoreMinimal.h"
#include "AS_CharacterBase.h"
#include "Components/WidgetComponent.h"
#include "Interaction/EnemyInterface.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "AS_Enemy.generated.h"

UCLASS()
class ABILITYSYSTEM_API AAS_Enemy : public AAS_CharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAS_Enemy();


	/** Enemy Interface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** End Enemy Interface */

	/** Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/** End Combat Interface */

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChangedDelegate;
	
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;
};
