// Fill out your copyright notice in the Description page of Project Settings.

#include "RotateObjects.h"

// Sets default values for this component's properties
URotateObjects::URotateObjects()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotateObjects::BeginPlay()
{
	Super::BeginPlay();

	mOwner = GetOwner();
	mInitRotation = mOwner->GetActorRotation();
	mTargetRotation = mInitRotation + OffsetRotation;	
}


// Called every frame
void URotateObjects::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bShouldRotate)
	{
		const FRotator CurrentRotation = mOwner->GetActorRotation();

		if (CurrentRotation.Equals(mTargetRotation, 0.005)) { return; }
		
		FRotator NewRotation = FMath::RInterpTo(CurrentRotation, mTargetRotation, DeltaTime, RotateInterTimeMod);
		mOwner->SetActorRotation(NewRotation);
	}
}

