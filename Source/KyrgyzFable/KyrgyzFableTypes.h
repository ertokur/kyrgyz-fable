// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "KyrgyzFableTypes.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMissionEventSignature);

DECLARE_LOG_CATEGORY_EXTERN(LogMission, Log, All);

USTRUCT(BlueprintType)
struct FMissionSteps
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> MissionStepNames;
};

UENUM(BlueprintType)
enum class EMissionStepState : uint8
{
	MSS_NotActive	UMETA(DisplayName = "Not Active"),
	MSS_Active		UMETA(DisplayName = "Active"),
	MSS_Completed	UMETA(DisplayName = "Completed")
};

//DELEGATES
///////////

//PROPERTIES
////////////

//COMPONENTS
////////////

//OVERRIDES
///////////

//FUNCTIONS
///////////