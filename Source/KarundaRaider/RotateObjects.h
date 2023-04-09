// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RotateObjects.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KARUNDARAIDER_API URotateObjects : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URotateObjects();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
		FRotator OffsetRotation;

	UPROPERTY(EditAnywhere)
		float RotateInterTimeMod = 5;

	bool bShouldRotate = true;
	AActor* mOwner;
	FRotator mInitRotation;
	FRotator mTargetRotation;
};
