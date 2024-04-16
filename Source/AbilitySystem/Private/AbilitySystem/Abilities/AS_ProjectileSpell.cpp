// Copyright Artur Hrytsiv


#include "AbilitySystem/Abilities/AS_ProjectileSpell.h"

#include "Actor/AS_Projectile.h"
#include "Interaction/CombatInterface.h"

void UAS_ProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                          const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
}

void UAS_ProjectileSpell::SpawnProjectile(const FVector& ProjectileTargetLoc)
{
	const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();
	if (!bIsServer) return;

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo());
	if(CombatInterface)
	{
		const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();
		FRotator Rotation = (ProjectileTargetLoc - SocketLocation).Rotation();
		Rotation.Pitch = 0.f;
		
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(SocketLocation);
		SpawnTransform.SetRotation(Rotation.Quaternion());
		// TODO: Set the Projectile Rotation
		
		AAS_Projectile* Projectile = GetWorld()->SpawnActorDeferred<AAS_Projectile>(ProjectileClass,
													   SpawnTransform,
													   GetOwningActorFromActorInfo(),
													   Cast<APawn>(GetOwningActorFromActorInfo()),
													   ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

		// TODO: Give the Projectile a Gameplay Effect Spec for causing Damage.
		
		Projectile->FinishSpawning(SpawnTransform);
	}
}
