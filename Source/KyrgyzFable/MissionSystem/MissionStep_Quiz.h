// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "MissionStep_Base.h"
#include "KyrgyzFable/UI/QuizScreen.h"
#include "MissionStep_Quiz.generated.h"

UCLASS()
class KYRGYZFABLE_API AMissionStep_Quiz : public AMissionStep_Base
{
	GENERATED_BODY()

public:
	AMissionStep_Quiz();

	virtual void Activate() override;
	
	virtual void Deactivate() override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditInstanceOnly, Category = "Default|Settings")
	UDataTable* QuizDataTable = nullptr;

	UPROPERTY(EditInstanceOnly, Category = "Default|Settings")
	TSubclassOf<UQuizScreen> QuizScreenWidgetClass = nullptr;
	
	UPROPERTY()
	UQuizScreen* QuizScreen = nullptr;
};