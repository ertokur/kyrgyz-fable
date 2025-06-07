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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	class UStaticMeshComponent* TriggerMesh;
	
protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};