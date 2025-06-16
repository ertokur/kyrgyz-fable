// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "MissionStep_Quiz.h"
#include "MissionStep_Quiz_Colors.generated.h"

UCLASS()
class KYRGYZFABLE_API AMissionStep_Quiz_Colors : public AMissionStep_Quiz
{
	GENERATED_BODY()

public:
	AMissionStep_Quiz_Colors();
	
	virtual void Activate() override;
	virtual void Deactivate() override;
	
protected:
	virtual void BeginPlay() override;
	virtual void SetTotalAnswers(int32 NewCount = 0) override;
	
private:
	UPROPERTY(EditInstanceOnly, Category = "Default|Settings", meta = (RequiredAssetDataTags  = "RowStructure=/Script/KyrgyzFable.QuizColorsTableRow"))
	UDataTable* QuizDataTable = nullptr;

	UPROPERTY(EditInstanceOnly, Category = "Default|Settings")
	TSubclassOf<class UQuizScreen_Colors> QuizScreenWidgetClass = nullptr;
	
	UPROPERTY()
	UQuizScreen_Colors* QuizScreen = nullptr;
};