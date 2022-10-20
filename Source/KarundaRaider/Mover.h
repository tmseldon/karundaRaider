// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KARUNDARAIDER_API UMover : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMover();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
		FVector MoveOffset;

	UPROPERTY(EditAnywhere)
		float MoveTime = 5;

	UPROPERTY(EditAnywhere)
		bool bShouldMove = false;
		
	FVector mOriginalLocation;
	FVector mCurrentLocation;
	FVector mTargetLocation;
	float mSpeed = 0;
};
