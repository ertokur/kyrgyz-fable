// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MissionStep_Base.h"
#include "KyrgyzFable/KyrgyzFableTypes.h"
#include "Mission.generated.h"

UCLASS(NotPlaceable, NotBlueprintable)
class KYRGYZFABLE_API AMission : public AActor
{
	GENERATED_BODY()

	friend class AMissionsController;
	
public:
	AMission();

	UPROPERTY(BlueprintAssignable, Category = MissionStep)
	FMissionEventSignature OnMissionCompleted;

	UFUNCTION(BlueprintPure, Category = MissionStep)
	FORCEINLINE FName GetMissionID() const { return MissionID; }

	UFUNCTION()
	virtual void StartMission();

	virtual void CompleteMission();

	virtual TArray<FQuizCollectableData> GetQuizCollectableData() const;
	
protected:
	virtual void BeginPlay() override;

private:
	FName MissionID;

	UPROPERTY()
	TArray<AMissionStep_Base*> MissionStepActors;

	FMissionSteps MissionSteps;

	int32 CurrentStepIndex = 0;

	UPROPERTY()
	AMissionStep_Base* CurrentStep = nullptr;

	AMissionStep_Base* GetMissionStepByIndex(const int32 Index);
};