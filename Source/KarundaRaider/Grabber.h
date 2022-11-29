// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KARUNDARAIDER_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
		void Release();

	UFUNCTION(BlueprintCallable)
		void Grab();


private:

	UPROPERTY(EditAnywhere)
		float mMaxGrabDistance = 400;

	UPROPERTY(EditAnywhere)
		float mMaxGrabRadius = 100;

	UPROPERTY(EditAnywhere)
		float mHoldingDistance = 200;

	FRotator mRotationGrabber;
	int mGapFrame = 0;

	UPhysicsHandleComponent* GetPhysicHandle() const;
	bool GetGrabbableInReach(FHitResult& FHitData) const;
};
