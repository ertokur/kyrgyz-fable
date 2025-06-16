// Erbol Tokur


#include "SaveSubsystem.h"
#include "PlayerProgress.h"
#include "PlayerSettings.h"
#include "Kismet/GameplayStatics.h"
#include "KyrgyzFable/KyrgyzFableTypes.h"
#include "KyrgyzFable/MissionSystem/MissionsController.h"
#include "GameFramework/PlayerStart.h"
#include "KyrgyzFable/Core/KFGameInstanceBase.h"
#include "KyrgyzFable/MissionSystem/Mission.h"

DEFINE_LOG_CATEGORY(LogKF);

USaveSubsystem::USaveSubsystem()
{
}

void USaveSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	PlayerSettings = TryLoadSettings();
	PlayerProgress = TryLoadProgress();

	if (PlayerSettings)
	{
		if (UKFGameInstanceBase* GI = Cast<UKFGameInstanceBase>(GetGameInstance()))
		{
			GI->SetLanguage(PlayerSettings->Language);
		}
	}
}

void USaveSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

UPlayerSettings* USaveSubsystem::TryLoadSettings()
{
	if (USaveGame* LoadedSave = UGameplayStatics::LoadGameFromSlot("PlayerSettings", 0))
	{
		return Cast<UPlayerSettings>(LoadedSave);
	}
	
	return nullptr;
}

UPlayerProgress* USaveSubsystem::TryLoadProgress()
{
	if (USaveGame* LoadedSave = UGameplayStatics::LoadGameFromSlot("PlayerProgress", 0))
	{
		return Cast<UPlayerProgress>(LoadedSave);
	}
	
	return nullptr;
}

UPlayerSettings* USaveSubsystem::GetPlayerSettings()
{
	return PlayerSettings ? PlayerSettings : PlayerSettings = TryLoadSettings();
}

UPlayerProgress* USaveSubsystem::GetPlayerProgress()
{
	return PlayerProgress ? PlayerProgress : PlayerProgress = TryLoadProgress();
}

void USaveSubsystem::SaveSettings()
{
	if (UPlayerSettings* Save = Cast<UPlayerSettings>(UGameplayStatics::CreateSaveGameObject(UPlayerSettings::StaticClass())))
	{
		if (UKFGameInstanceBase* GI = Cast<UKFGameInstanceBase>(GetGameInstance()))
		{
			Save->Language = GI->GetLanguage();

			if (UGameplayStatics::SaveGameToSlot(Save, "PlayerSettings", 0))
			{
				PlayerSettings = Save;
				UE_LOG(LogKF, Display, TEXT("Settings saved successfully!"));
				return;
			}
		}
	}

	UE_LOG(LogKF, Warning, TEXT("Settings did not saved!"));
}

void USaveSubsystem::SaveProgress(const AMissionsController* MissionsController)
{
	if (UPlayerProgress* Save = Cast<UPlayerProgress>(UGameplayStatics::CreateSaveGameObject(UPlayerProgress::StaticClass())))
	{
		if (APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0))
		{
			if (APawn* Pawn = PC->GetPawn())
			{
				Save->PlayerLocation = Pawn->GetActorLocation();
				Save->PlayerRotation = Pawn->GetActorRotation();
			}
		}
		else
		{
			if (APlayerStart* PlayerStart = Cast<APlayerStart>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerStart::StaticClass())))
			{
				Save->PlayerLocation = PlayerStart->GetActorLocation();
				Save->PlayerRotation = PlayerStart->GetActorRotation();
			}
		}
	
		if (MissionsController)
		{
			Save->LastCompletedMissionIndex = MissionsController->GetCurrentMissionIndex();

			if (GetPlayerProgress())
			{
				Save->QuizCollectableData = PlayerProgress->QuizCollectableData;
			}

			if (AMission* CurrentMission = MissionsController->GetCurrentMission())
			{
				Save->QuizCollectableData.Append(CurrentMission->GetQuizCollectableData());
			}
		}

		if (UGameplayStatics::SaveGameToSlot(Save, "PlayerProgress", 0))
		{
			PlayerProgress = Save;
			UE_LOG(LogKF, Display, TEXT("Progress saved successfully!"));
			return;
		}
	}
	
	UE_LOG(LogKF, Warning, TEXT("Progress did not saved!"));
}

void USaveSubsystem::ClearProgress()
{
	UGameplayStatics::DeleteGameInSlot("PlayerProgress", 0);
	PlayerProgress = nullptr;
}