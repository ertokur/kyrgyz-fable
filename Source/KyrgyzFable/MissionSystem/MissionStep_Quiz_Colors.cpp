// Erbol Tokur


#include "MissionStep_Quiz_Colors.h"
#include "KyrgyzFable/UI/QuizScreen_Colors.h"


AMissionStep_Quiz_Colors::AMissionStep_Quiz_Colors()
{
}

void AMissionStep_Quiz_Colors::Activate()
{
	Super::Activate();
	
	if (QuizScreenWidgetClass)
	{
		if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
		{
			QuizScreen = Cast<UQuizScreen_Colors>(CreateWidget(PC, QuizScreenWidgetClass));

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

void AMissionStep_Quiz_Colors::Deactivate()
{
	Super::Deactivate();

	if (QuizScreen)
	{
		QuizScreen->RemoveFromParent();
		QuizScreen = nullptr;
	}
}

void AMissionStep_Quiz_Colors::BeginPlay()
{
	Super::BeginPlay();
}

void AMissionStep_Quiz_Colors::SetTotalAnswers(int32 NewCount)
{
	if (QuizDataTable)
	{
		Super::SetTotalAnswers(QuizDataTable->GetRowNames().Num());
	}
}