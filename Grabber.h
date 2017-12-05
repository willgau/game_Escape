// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UGrabber : public UActorComponent
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

private :
	
	float Reach = 100.f;
	
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	//Ray-cast and grab what it reach
	void Grab();
	//When the grab key is release
	void Release();

	//Find (assumued) attach physics component
	void FindPhysicsHandleComponent();
	//Setup (assumed) input component
	void SetupInputComponent();
	//return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();
	//Return current start of reach line
	FVector GetReachLinestart();
	//Return current end of reach line
	FVector GetReachLineEnd();
};
