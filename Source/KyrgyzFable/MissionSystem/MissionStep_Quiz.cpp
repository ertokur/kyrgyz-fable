// Erbol Tokur


#include "MissionStep_Quiz.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

AMissionStep_Quiz::AMissionStep_Quiz()
{
}

void AMissionStep_Quiz::Activate()
{
	Super::Activate();
	SetActorTickEnabled(true);

	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		if (ACharacter* Character = Cast<ACharacter>(PC->GetPawn()))
		{
			Character->GetCharacterMovement()->StopMovementImmediately();
		}

		PC->FlushPressedKeys();
		PC->SetInputMode(FInputModeUIOnly());
		PC->SetShowMouseCursor(true);
	}
}

void AMissionStep_Quiz::Deactivate()
{
	Super::Deactivate();

	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		PC->SetInputMode(FInputModeGameOnly());
		PC->SetShowMouseCursor(false);
	}
}

void AMissionStep_Quiz::CompleteStep()
{
	SetActorTickEnabled(false);
	CompleteDate = FDateTime::Now();
	Super::CompleteStep();
}

FQuizCollectableData AMissionStep_Quiz::CollectData() const
{
	FQuizCollectableData OutData;

	if (QuizNamesDataTable)
	{
		if (FLocalizationTableRow* Localization = QuizNamesDataTable->FindRow<FLocalizationTableRow>(QuizNameKey, ""))
		{
			OutData.QuizName = Localization->Localization;
		}
	}
	
	OutData.CorrectAnswers = CorrectAnswers;
	OutData.TotalAnswers = TotalAnswers;
	OutData.SolutionTime = SolutionTime;
	OutData.CompleteDate = CompleteDate;

	UE_LOG(LogKF, Display, TEXT("----- COLLECT -----"));
	UE_LOG(LogKF, Display, TEXT("QuizName: %s"), *OutData.QuizName.English.ToString());
	UE_LOG(LogKF, Display, TEXT("Total Answers: %i"), OutData.TotalAnswers);
	UE_LOG(LogKF, Display, TEXT("Correct Answers: %i"), OutData.CorrectAnswers);
	UE_LOG(LogKF, Display, TEXT("Solution Time: %f"), OutData.SolutionTime);
	UE_LOG(LogKF, Display, TEXT("Date: %s"), *OutData.CompleteDate.ToString());
	
	return OutData;
}

void AMissionStep_Quiz::AddCorrectAnswerCount()
{
	CorrectAnswers++;
}

void AMissionStep_Quiz::BeginPlay()
{
	Super::BeginPlay();
	SetTotalAnswers();
}

void AMissionStep_Quiz::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (GetState() == EMissionStepState::MSS_Active)
	{
		SolutionTime += DeltaSeconds;
	}
}

void AMissionStep_Quiz::SetTotalAnswers(int32 NewCount)
{
	TotalAnswers = NewCount;
}