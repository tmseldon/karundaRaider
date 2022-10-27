// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Components/SceneComponent.h"
#include "Engine/EngineTypes.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...


}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//if (mGapFrame % 10 == 0)
	//{
	//	//Rotacion
	//	mRotationGrabber = GetComponentRotation();
	//	FString RotationText = mRotationGrabber.ToCompactString();

	//	UE_LOG(LogTemp, Display, TEXT("Rotacion del componente es %s"), *RotationText);


	//	//Tiempo
	//	UWorld* World = GetWorld();
	//	float TotalTime = World->TimeSeconds;

	//	UE_LOG(LogTemp, Display, TEXT("Tiempo total es de %f"), TotalTime);
	//}

	//mGapFrame++;

}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Display, TEXT("Release button"));
}

void UGrabber::Grab()
{
	//Setup Ray
	FVector StartPoint = GetComponentLocation();
	FVector EndPoint = StartPoint + mMaxGrabDistance * GetForwardVector();

	//Debug Ray
	//DrawDebugLine(GetWorld(), StartPoint, EndPoint, FColor::Red);

	//Raycast info
	FCollisionShape Sphere = FCollisionShape::MakeSphere(mMaxGrabRadius);
	FHitResult FHitInfo;

	bool bHasHit = GetWorld()->SweepSingleByChannel
	(
		FHitInfo,
		StartPoint,
		EndPoint,
		FQuat::Identity,
		ECC_GameTraceChannel2,
		Sphere
	);

	if (bHasHit)
	{
		FString NombreActor = FHitInfo.GetActor()->GetActorNameOrLabel();
		UE_LOG(LogTemp, Display, TEXT("El nombre del obejeto es %s"), *NombreActor);
	}
}

