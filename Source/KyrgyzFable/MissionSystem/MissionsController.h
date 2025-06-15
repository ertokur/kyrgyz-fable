// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KyrgyzFable/KyrgyzFableTypes.h"
#include "MissionsController.generated.h"

UCLASS()
class KYRGYZFABLE_API AMissionsController : public AActor
{
	GENERATED_BODY()

public:
	AMissionsController();

	UPROPERTY(BlueprintAssignable, Category = MissionStep)
	FMissionEventSignature OnAllMissionsCompleted;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Default|Settings")
	TMap<FName, FMissionSteps> MissionsList;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void StartNextMission();
	
	virtual class AMission* CreateMission(FName MissionID);

private:
	UPROPERTY()
	TArray<class AMissionStep_Base*> MissionStepActors;

	UPROPERTY()
	AMission* CurrentMission = nullptr;

	int32 CurrentMissionIndex = 0;

	TArray<FName> CompletedMissions;

	bool IsMissionStepInList(const AMissionStep_Base* MissionStep) const;

	FName GetMissionIDByIndex(const int32 Index) const;
};