// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "DrawDebugHelpers.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	
	//if (UGrabber::GetPhysicHandle())
	//{
	//	FString NombreComponente = UGrabber::GetPhysicHandle()->GetName();
	//	UE_LOG(LogTemp, Display, TEXT("El nombre de la componente es %s"), *NombreComponente);
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("El handlePhysics no existe, el puntero es null"));
	//}

}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UPhysicsHandleComponent* PhysicHandle = UGrabber::GetPhysicHandle();

	if (PhysicHandle == nullptr || PhysicHandle->GetGrabbedComponent() == nullptr ) { return; }
	 
	FVector GrabObjectPos = GetComponentLocation() + GetForwardVector() * mHoldingDistance;
	PhysicHandle->SetTargetLocationAndRotation(GrabObjectPos, GetComponentRotation());
	

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

	UPrimitiveComponent* ComponentGrabbed = UGrabber::GetPhysicHandle()->GetGrabbedComponent();
	if (ComponentGrabbed == nullptr) { return; }

	ComponentGrabbed->WakeAllRigidBodies();
	UGrabber::GetPhysicHandle()->ReleaseComponent();
}

void UGrabber::Grab()
{
	UE_LOG(LogTemp, Display, TEXT("Calling grab button"));

	UPhysicsHandleComponent* PhysicHandle = UGrabber::GetPhysicHandle();
	if (PhysicHandle == nullptr) { return; }

	//Init variables for references	
	FHitResult FHitInfo;
	bool bHasHit = GetGrabbableInReach(FHitInfo);

	if (bHasHit)
	{
		UPrimitiveComponent* HitComponent = FHitInfo.GetComponent();
		HitComponent->WakeAllRigidBodies();

		PhysicHandle->GrabComponentAtLocationWithRotation
		(
			HitComponent,
			NAME_None,
			FHitInfo.ImpactPoint,
			GetComponentRotation()
		);

		//////Debug Info
		//FString NombreActor = FHitInfo.GetActor()->GetActorNameOrLabel();
		//UE_LOG(LogTemp, Display, TEXT("El nombre del obejeto es %s"), *NombreActor);
		//
		//DrawDebugSphere(GetWorld(), FHitInfo.Location, 10, 10, FColor::Yellow, false, 5);
		//DrawDebugSphere(GetWorld(), FHitInfo.ImpactPoint, 10, 10, FColor::Red, false, 5);
	}
}

bool UGrabber::GetGrabbableInReach(FHitResult& FHitData) const
{
	//Setup Ray
	FVector StartPoint = GetComponentLocation();
	FVector EndPoint = StartPoint + mMaxGrabDistance * GetForwardVector();

	////Debug Ray
	//DrawDebugLine(GetWorld(), StartPoint, EndPoint, FColor::Red);
	//DrawDebugSphere(GetWorld(), EndPoint, 5, 10, FColor::Green, false, 5);

	//Raycast info
	FCollisionShape Sphere = FCollisionShape::MakeSphere(mMaxGrabRadius);

	return GetWorld()->SweepSingleByChannel
	(
		FHitData,
		StartPoint,
		EndPoint,
		FQuat::Identity,
		ECC_GameTraceChannel2,
		Sphere
	);
}


UPhysicsHandleComponent * UGrabber::GetPhysicHandle() const
{
	UPhysicsHandleComponent* Result = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (Result == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("No UPhysicsHandleComponent found on player"));
	}
	return Result;
}