// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "Localizable.h"
#include "KyrgyzFable/KyrgyzFableTypes.h"
#include "Blueprint/UserWidget.h"
#include "DialogScreen.generated.h"

UCLASS(Abstract)
class KYRGYZFABLE_API UDialogScreen : public UUserWidget, public ILocalizable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FMissionEventSignature OnDialogCompleted;

	UPROPERTY(BlueprintReadOnly)
	UDataTable* DialogDataTable = nullptr;
};