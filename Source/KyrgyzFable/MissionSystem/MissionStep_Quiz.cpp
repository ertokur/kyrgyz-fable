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

	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		if (QuizScreenWidgetClass)
		{
			QuizScreen = Cast<UQuizScreen>(CreateWidget(PC, QuizScreenWidgetClass));

			if (QuizScreen)
			{
				QuizScreen->QuizDataTable = QuizDataTable;
				QuizScreen->AddToViewport();

				if (ACharacter* Character = Cast<ACharacter>(PC->GetPawn()))
				{
					Character->GetCharacterMovement()->StopMovementImmediately();
				}

				PC->FlushPressedKeys();
				PC->SetInputMode(FInputModeUIOnly());
				PC->SetShowMouseCursor(true);
				QuizScreen->OnQuizCompleted.AddDynamic(this, &AMissionStep_Base::CompleteStep);
			}
		}
	}
}

void AMissionStep_Quiz::Deactivate()
{
	Super::Deactivate();

	if (QuizScreen)
	{
		QuizScreen->RemoveFromViewport();
		QuizScreen = nullptr;

		if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
		{
			PlayerController->SetInputMode(FInputModeGameOnly());
			PlayerController->SetShowMouseCursor(false);
		}
	}
}

void AMissionStep_Quiz::BeginPlay()
{
	Super::BeginPlay();
	
}