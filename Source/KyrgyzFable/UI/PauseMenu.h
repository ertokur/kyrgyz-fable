// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "Localizable.h"
#include "Blueprint/UserWidget.h"
#include "PauseMenu.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPauseSignature);

/**
 * 
 */
UCLASS()
class KYRGYZFABLE_API UPauseMenu : public UUserWidget, public ILocalizable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FPauseSignature OnPauseExit;
};