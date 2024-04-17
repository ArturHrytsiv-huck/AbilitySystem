// Copyright Artur Hrytsiv

#pragma once

#include "CoreMinimal.h"
#include "AS_GameplayAbility.h"
#include "AS_ProjectileSpell.generated.h"

class AAS_Projectile;
/**
 * 
 */
UCLASS()
class ABILITYSYSTEM_API UAS_ProjectileSpell : public UAS_GameplayAbility
{
	GENERATED_BODY()

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	                             const FGameplayEventData* TriggerEventData) override;

	UFUNCTION(BlueprintCallable)
	void SpawnProjectile(const FVector& ProjectileTargetLoc);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AAS_Projectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> DamageEffectClass;
};
