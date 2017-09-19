// Copyright Nick Bellamy 2017

#pragma once

#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void OpenDoor();
	void CloseDoor();

	UPROPERTY(BluePrintAssignable)
		FOnOpenRequest OnOpenRequest;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;	

private:
	UPROPERTY(EditAnywhere)
		float OpenAngle = -90.0f;
	
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 1.0f;

	float LastDoorOpenTime;
	
	// The owning door
	AActor* Owner = nullptr;

	// Returns total mass in kg
	float GetTotalMassOfActorsOnPlate() const;

	UPROPERTY(EditAnywhere)
		float TriggerMass = 30.0f;
};
