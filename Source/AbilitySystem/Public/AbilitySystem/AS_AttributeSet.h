// Copyright Artur Hrytsiv

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"

#include "AS_AttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties() {}

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayEffectContextHandle EffectContextHandle;

	//~ Source
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UAbilitySystemComponent* SourceASC;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AActor* SourceAvatarActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AController* SourceController;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ACharacter* SourceCharacter;

	//~ Target
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UAbilitySystemComponent* TargetASC;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AActor* TargetAvatarActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AController* TargetController;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ACharacter* TargetCharacter;

};

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM_API UAS_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UAS_AttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAS_AttributeSet, Health);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAS_AttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAS_AttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAS_AttributeSet, MaxMana);

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Properties) const;
};
