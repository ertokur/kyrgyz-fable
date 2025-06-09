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

	//COMPONENTS
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = MissionStep)
	UBillboardComponent* Billboard;
	////////////
	
	//DELEGATES
	UPROPERTY(BlueprintAssignable, Category = MissionStep)
	FMissionEventSignature OnAllMissionsCompleted;
	///////////
	
	//PROPERTIES
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Default|Settings")
	TMap<FName, FMissionSteps> MissionsList;
	////////////

protected:
	//OVERRIDES
	virtual void BeginPlay() override;
	///////////
	
	//FUNCTIONS
	UFUNCTION()
	virtual void StartNextMission();
	
	virtual class AMission* CreateMission(FName MissionID);
	///////////

private:
	//PROPERTIES
	UPROPERTY()
	TArray<class AMissionStep_Base*> MissionStepActors;

	UPROPERTY()
	AMission* CurrentMission = nullptr;

	int32 CurrentMissionIndex = 0;

	TArray<FName> CompletedMissions;
	////////////

	//FUNCTIONS
	bool IsMissionStepInList(const AMissionStep_Base* MissionStep) const;

	FName GetMissionIDByIndex(const int32 Index) const;
	///////////
};