// Copyright Nick Bellamy 2017

#pragma once

#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
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

private:
	// Range of grabbing functionality
	float Reach = 100.0f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	// Ray-cast and grab what is in reach
	void Grab();

	// Called when grab is released
	void Release();

	// Find assumed attached physics handle
	void FindPhysicsHandleComponent();

	// Set-up assumed attached input component
	void SetUpInputComponent();

	// Return hit for first physics body in reach
	FHitResult GetFirstPhysicsBodyInReach() const;

	// Returns start of current reach line
	FVector GetReachLineStart() const;

	// Returns end of current reach line
	FVector GetReachLineEnd() const;
};
