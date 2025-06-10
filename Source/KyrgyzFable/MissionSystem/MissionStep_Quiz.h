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
	//FUNCTIONS
	AMissionStep_Quiz();
	///////////

	//OVERRIDES
	virtual void Activate() override;
	
	virtual void Deactivate() override;
	///////////

protected:
	//OVERRIDES
	virtual void BeginPlay() override;
	///////////

private:
	//PROPERTIES
	UPROPERTY(EditInstanceOnly, Category = "Default|Settings")
	UDataTable* QuizDataTable = nullptr;

	UPROPERTY(EditInstanceOnly, Category = "Default|Settings")
	TSubclassOf<UQuizScreen> QuizScreenWidgetClass = nullptr;
	
	UPROPERTY()
	UQuizScreen* QuizScreen = nullptr;
	////////////
};