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

	GetOverlappingActors(mOverlappingActors);
	if (mOverlappingActors.Num() > 0)
	{
		for(AActor* actorsOver : mOverlappingActors)
		{
			UE_LOG(LogTemp, Display, TEXT("Overlapping actor de nombre %s"), *actorsOver->GetActorNameOrLabel());
		}
	}
}