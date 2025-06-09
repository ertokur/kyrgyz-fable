// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "KyrgyzFableTypes.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMissionEventSignature);

DECLARE_LOG_CATEGORY_EXTERN(LogMission, Log, All);

UENUM(BlueprintType)
enum class EMissionStepState : uint8
{
	MSS_NotActive	UMETA(DisplayName = "Not Active"),
	MSS_Active		UMETA(DisplayName = "Active"),
	MSS_Completed	UMETA(DisplayName = "Completed")
};

UENUM(BlueprintType)
enum class ELanguage : uint8
{
	L_Russian		UMETA(DisplayName = "Russian"),
	L_Kyrgyz		UMETA(DisplayName = "Kyrgyz"),
	L_English		UMETA(DisplayName = "English")
};

USTRUCT(BlueprintType)
struct FMissionSteps
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> MissionStepNames;
};

USTRUCT(BlueprintType)
struct FLocalization
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Russian;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Kyrgyz;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText English;
};

USTRUCT(BlueprintType)
struct FLocalizationTableRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLocalization Localization;
};

USTRUCT(BlueprintType)
struct FDialogTableRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLocalization Localization;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* Sound = nullptr;
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