// Erbol Tokur

#include "Mission.h"
#include "MissionStep_Base.h"

AMission::AMission()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMission::BeginPlay()
{
	Super::BeginPlay();
}

void AMission::StartMission()
{
	if (CurrentStep)
	{
		CurrentStep->OnStepCompleted.Clear();
	}
	else
	{
		UE_LOG(LogMission, Display, TEXT("[%s] - Mission Started"), *GetMissionID().ToString());
	}
	
	CurrentStep = GetMissionStepByIndex(CurrentStepIndex);
	
	if (CurrentStep)
	{
		CurrentStep->OnStepCompleted.AddDynamic(this, &AMission::StartMission);
		CurrentStep->Activate();
		CurrentStepIndex++;
	}
	else
	{
		UE_LOG(LogMission, Display, TEXT("[%s] - Mission Completed"), *GetMissionID().ToString());
		OnMissionCompleted.Broadcast();
	}
}

void AMission::CompleteMission()
{
	
}

AMissionStep_Base* AMission::GetMissionStepByIndex(const int32 Index)
{
	if (MissionSteps.MissionStepNames.IsValidIndex(Index))
	{
		FName StepName = MissionSteps.MissionStepNames[Index];
		for (const auto& Iter : MissionStepActors)
		{
			if (Iter->GetID() == StepName)
			{
				return Iter;
			}
		}
	}
	
	return nullptr;
}