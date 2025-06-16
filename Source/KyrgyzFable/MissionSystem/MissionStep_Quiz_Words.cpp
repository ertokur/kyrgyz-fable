// Erbol Tokur


#include "MissionStep_Quiz_Words.h"
#include "KyrgyzFable/UI/QuizScreen_Words.h"


AMissionStep_Quiz_Words::AMissionStep_Quiz_Words()
{
}

void AMissionStep_Quiz_Words::Activate()
{
	Super::Activate();

	if (QuizScreenWidgetClass)
	{
		if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
		{
			QuizScreen = Cast<UQuizScreen_Words>(CreateWidget(PC, QuizScreenWidgetClass));

			if (QuizScreen)
			{
				QuizScreen->QuizDataTable = QuizDataTable;
				QuizScreen->QuizActor = this;
				QuizScreen->AddToViewport();
				QuizScreen->OnQuizCompleted.AddDynamic(this, &AMissionStep_Base::CompleteStep);
			}	
		}
	}
}

void AMissionStep_Quiz_Words::Deactivate()
{
	Super::Deactivate();

	if (QuizScreen)
	{
		QuizScreen->RemoveFromParent();
		QuizScreen = nullptr;
	}
}

void AMissionStep_Quiz_Words::BeginPlay()
{
	Super::BeginPlay();
}

void AMissionStep_Quiz_Words::SetTotalAnswers(int32 NewCount)
{
	if (QuizDataTable)
	{
		Super::SetTotalAnswers(QuizDataTable->GetRowNames().Num());
	}
}