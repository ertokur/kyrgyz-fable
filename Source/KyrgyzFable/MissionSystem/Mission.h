// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KyrgyzFable/KyrgyzFableTypes.h"
#include "Mission.generated.h"

UCLASS(NotPlaceable, NotBlueprintable)
class KYRGYZFABLE_API AMission : public AActor
{
	GENERATED_BODY()

	friend class AMissionsController;
	
public:
	AMission();

	//DELEGATES
	UPROPERTY(BlueprintAssignable, Category = MissionStep)
	FMissionEventSignature OnMissionCompleted;
	///////////
	
	//FUNCTIONS
	UFUNCTION(BlueprintPure, Category = MissionStep)
	FORCEINLINE FName GetMissionID() const { return MissionID; }

	UFUNCTION()
	virtual void StartMission();

	virtual void CompleteMission();
	///////////
	
protected:
	//OVERRIDES
	virtual void BeginPlay() override;
	///////////

private:
	//PROPERTIES
	FName MissionID;

	UPROPERTY()
	TArray<class AMissionStep_Base*> MissionStepActors;

	FMissionSteps MissionSteps;

	int32 CurrentStepIndex = 0;

	UPROPERTY()
	AMissionStep_Base* CurrentStep = nullptr;

	
	////////////

	//FUNCTIONS
	AMissionStep_Base* GetMissionStepByIndex(const int32 Index);
	///////////
};