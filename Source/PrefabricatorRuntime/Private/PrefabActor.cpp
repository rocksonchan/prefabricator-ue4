//$ Copyright 2015-18, Code Respawn Technologies Pvt Ltd - All Rights Reserved $//

#include "PrefabActor.h"

#include "PrefabComponent.h"

#include "Components/BillboardComponent.h"
#include "Engine/PointLight.h"

APrefabActor::APrefabActor(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
	PrefabComponent = ObjectInitializer.CreateDefaultSubobject<UPrefabComponent>(this, "PrefabComponent");
	RootComponent = PrefabComponent;

	Sprite = ObjectInitializer.CreateDefaultSubobject<UBillboardComponent>(this, "Sprite");
	Sprite->SetupAttachment(RootComponent);
}

void APrefabActor::Destroyed()
{
	Super::Destroyed();

	// Destroy all attached actors
	{
		TArray<AActor*> AttachedActors;
		GetAttachedActors(AttachedActors);
		for (AActor* AttachedActor : AttachedActors) {
			AttachedActor->Destroy();
		}
	}
}

#if WITH_EDITOR
void APrefabActor::PostEditChangeProperty(struct FPropertyChangedEvent& e)
{
	Super::PostEditChangeProperty(e);

}

void APrefabActor::PostDuplicate(EDuplicateMode::Type DuplicateMode)
{
	Super::PostDuplicate(DuplicateMode);

}

#endif // WITH_EDITOR


