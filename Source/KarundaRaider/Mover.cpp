// Fill out your copyright notice in the Description page of Project Settings.

#include "Mover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	//Getting initial parameters 
	mOwner = GetOwner();
	mOriginalLocation = mOwner->GetTargetLocation();
	mTargetLocation = mOriginalLocation + MoveOffset;
	mSpeed = FVector::Distance(mOriginalLocation, mTargetLocation) / MoveTime;

	//C�digo de prueba de punteros y log
	//
	//AActor* Owner = GetOwner();
	////FString NameOwner = (*Owner).GetActorNameOrLabel();
	//FString NameOwner = Owner->GetActorNameOrLabel();
	////FVector LocationOwner = Owner->GetActorLocation();
	//FString Location = Owner->GetActorLocation().ToCompactString();
	//UE_LOG(LogTemp, Display,
	//		TEXT("Hellooo solo al inicio, este es el address %u, el nombre es %s, la ubicacion es en %s"), 
	//		Owner, *NameOwner, *Location);

}

void UMover::SetShouldMove(bool bNewCondition)
{
	bShouldMove = bNewCondition;
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	FVector CurrentLocation = GetOwner()->GetTargetLocation();
	FVector FinalLocation = mOriginalLocation;

	if (bShouldMove)
	{
		FinalLocation = mTargetLocation;
	}

	if (!FMath::IsNearlyZero((FinalLocation - CurrentLocation).SizeSquared()))
	{
		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, FinalLocation, DeltaTime, mSpeed);
		mOwner->SetActorLocation(NewLocation);
		// UE_LOG(LogTemp, Display, TEXT("Estoy moviemdome %f"), (FinalLocation - CurrentLocation).SizeSquared());
	}
}

