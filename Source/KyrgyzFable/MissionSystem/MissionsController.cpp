// Erbol Tokur


#include "MissionsController.h"
#include "Kismet/GameplayStatics.h"
#include "MissionStep_Base.h"
#include "Mission.h"
#include "Components/BillboardComponent.h"

AMissionsController::AMissionsController()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

void AMissionsController::BeginPlay()
{
	Super::BeginPlay();

	if (!GetWorld() || MissionsList.Num() == 0)
		return;

	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMissionStep_Base::StaticClass(), OutActors);
	
	for (const auto& Iter : OutActors)
	{
		if (AMissionStep_Base* MissionStep = Cast<AMissionStep_Base>(Iter))
		{
			if (IsMissionStepInList(MissionStep))
			{
				MissionStepActors.Add(MissionStep);
			}
		}
	}

	//TODO: add load from save

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMissionsController::StartNextMission, .1f, false);
}

void AMissionsController::StartNextMission()
{
	if (!GetWorld())
		return;
	
	if (CurrentMission)
	{
		CurrentMissionIndex++;
		CurrentMission->Destroy();
		CurrentMission = nullptr;

		//TODO: save progress
	}

	FName NewMissionID = GetMissionIDByIndex(CurrentMissionIndex);

	if (NewMissionID == NAME_None)
	{
		UE_LOG(LogMission, Display, TEXT("All Missions Completed"));
		OnAllMissionsCompleted.Broadcast();
		return;
	}
	
	CurrentMission = CreateMission(NewMissionID);

	if (CurrentMission)
	{
		CurrentMission->OnMissionCompleted.AddDynamic(this, &AMissionsController::StartNextMission);
		CurrentMission->StartMission();
	}
}

bool AMissionsController::IsMissionStepInList(const AMissionStep_Base* MissionStep) const
{
	if (MissionStep)
	{
		for (const auto& Iter : MissionsList)
		{
			if (Iter.Value.MissionStepNames.Contains(MissionStep->GetID()))
			{
				return true;
			}
		}
	}
	
	return false;
}

FName AMissionsController::GetMissionIDByIndex(const int32 Index) const
{
	TArray<FName> MissionIDs;
	MissionsList.GetKeys(MissionIDs);

	if (MissionIDs.IsValidIndex(Index))
	{
		return MissionIDs[Index];
	}
	
	return NAME_None;
}

AMission* AMissionsController::CreateMission(FName MissionID)
{
	AMission* OutMission = GetWorld()->SpawnActorDeferred<AMission>(AMission::StaticClass(), FTransform::Identity, this);
	
	if (OutMission)
	{
		OutMission->MissionID = MissionID;

		if (FMissionSteps* StepNames = MissionsList.Find(MissionID))
		{
			OutMission->MissionSteps = *StepNames;
			
			for (const auto& Iter : MissionStepActors)
			{
				if (StepNames->MissionStepNames.Contains(Iter->GetID()))
				{
					OutMission->MissionStepActors.Add(Iter);
				}
			}
		}
	}
	
	return OutMission;
}