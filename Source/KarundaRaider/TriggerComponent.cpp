// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("Hello from the trigger box"));
}

// Called every frame
void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	AActor* PotentialActor = GetAcceptableActor();
	if (PotentialActor != nullptr) 
	{
		UPrimitiveComponent* RootPotentialActor = Cast<UPrimitiveComponent>(PotentialActor->GetRootComponent());
		// Setting the object fixed to this actor
		if (RootPotentialActor != nullptr)
		{
			RootPotentialActor->SetSimulatePhysics(false);
		}

		PotentialActor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
		mMover->SetShouldMove(true);
		UE_LOG(LogTemp, Display, TEXT("Desbloqueando con %s"), *PotentialActor->GetActorNameOrLabel());
	}
	else
	{
		mMover->SetShouldMove(false);
	}
}

void UTriggerComponent::SetMover(UMover* NewMover)
{
	mMover = NewMover;
}

AActor* UTriggerComponent::GetAcceptableActor() const
{
	TArray <AActor*> overlappingActors;
	GetOverlappingActors(overlappingActors);

	if (overlappingActors.Num() == 0) { return nullptr; }

	for (AActor* actorsOver : overlappingActors)
	{
		if (actorsOver->ActorHasTag(mAcceptableTagActor))
		{
			return actorsOver;
		}
	}

	return nullptr;
}