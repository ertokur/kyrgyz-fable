// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "Localizable.h"
#include "KyrgyzFable/KyrgyzFableTypes.h"
#include "Blueprint/UserWidget.h"
#include "QuizScreen_Base.generated.h"

/**
 * 
 */
UCLASS()
class KYRGYZFABLE_API UQuizScreen_Base : public UUserWidget, public ILocalizable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FMissionEventSignature OnQuizCompleted;

	UPROPERTY(BlueprintReadOnly)
	UDataTable* QuizDataTable = nullptr;

	UPROPERTY(BlueprintReadOnly)
	AMissionStep_Quiz* QuizActor = nullptr;
};