// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "MissionStep_Base.h"
#include "MissionStep_Trigger.generated.h"

UCLASS()
class KYRGYZFABLE_API AMissionStep_Trigger : public AMissionStep_Base
{
	GENERATED_BODY()

public:
	AMissionStep_Trigger();

	//COMPONENTS
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = MissionStep)
	UStaticMeshComponent* TriggerMesh = nullptr;
	////////////

	//OVERRIDES
	virtual void Activate() override;

	virtual void Deactivate() override;
	///////////
protected:
	//OVERRIDES
	virtual void BeginPlay() override;
	///////////

private:
	//FUNCTIONS
	UFUNCTION()
	void OnTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	///////////
};