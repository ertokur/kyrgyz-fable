// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KyrgyzFable/KyrgyzFableTypes.h"
#include "MissionStep_Base.generated.h"


UCLASS(Abstract)
class KYRGYZFABLE_API AMissionStep_Base : public AActor
{
	GENERATED_BODY()

public:
	AMissionStep_Base();
	
	FMissionEventSignature OnStepCompleted;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = MissionStep)
	class UTextRenderComponent* TextRender = nullptr;
	
	UFUNCTION(BlueprintPure, Category = MissionStep)
	FORCEINLINE FName GetID() const { return ID; }

	UFUNCTION(BlueprintPure, Category = MissionStep)
	FORCEINLINE EMissionStepState GetState() const { return State; }

	UFUNCTION()
	virtual void Activate();

	UFUNCTION()
	virtual void CompleteStep();

	UFUNCTION()
	virtual void Deactivate();

protected:
	virtual void BeginPlay() override;
	
	virtual void OnConstruction(const FTransform& Transform) override;

private:
	UPROPERTY(EditInstanceOnly, Category = "Default|Settings")
	FName ID;

	EMissionStepState State = EMissionStepState::MSS_NotActive;
};