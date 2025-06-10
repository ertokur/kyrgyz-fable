// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "Localizable.h"
#include "KyrgyzFable/KyrgyzFableTypes.h"
#include "Blueprint/UserWidget.h"
#include "QuizScreen.generated.h"

/**
 * 
 */
UCLASS()
class KYRGYZFABLE_API UQuizScreen : public UUserWidget, public ILocalizable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FMissionEventSignature OnQuizCompleted;

	UPROPERTY(BlueprintReadOnly)
	UDataTable* QuizDataTable = nullptr;
};