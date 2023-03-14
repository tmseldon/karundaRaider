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

	//Getting initial parameters 
	//mOwner = GetOwner();
	//mRotAxis = mOwner->GetActorUpVector();
	//mAngularSpeed = AngleToRotate / RotateTime;
	
	//mTargetDirection = mOriginalDirection.RotateAngleAxis(AngleToRotate, mOwner->GetActorUpVector());
	//mSpeed = FVector::Distance(mOriginalLocation, mTargetLocation) / MoveTime;
	
}


// Called every frame
void URotateObjects::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	FRotator CurrentRotation = mOwner->GetActorRotation();
	FRotator TargetRotation = mInitRotation;

	if (bShouldRotate)
	{
		TargetRotation = mInitRotation + OffsetRotation;

	}


	


	//if (mLimitTime > RotateTime) { return; }
	//
	//mDeltaRot = FQuat(mRotAxis, mAngularSpeed/DeltaTime);
	//mOwner->AddActorLocalRotation(mDeltaRot, false, 0, ETeleportType::None);
	//mLimitTime+= DeltaTime;
}

