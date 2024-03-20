// Copyright Artur Hrytsiv


#include "Actor/AS_EffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/AS_AttributeSet.h"


AAS_EffectActor::AAS_EffectActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void AAS_EffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	// TODO: FIX
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UAS_AttributeSet* AS_AttributeSet = Cast<UAS_AttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAS_AttributeSet::StaticClass()));

		UAS_AttributeSet* MutableAttributeSet = const_cast<UAS_AttributeSet*>(AS_AttributeSet);
		MutableAttributeSet->SetHealth(AS_AttributeSet->GetHealth() + 25.f);
	}
}

void AAS_EffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void AAS_EffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAS_EffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AAS_EffectActor::OnEndOverlap);
}

