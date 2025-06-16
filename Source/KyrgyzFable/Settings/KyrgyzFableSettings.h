// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "KyrgyzFableSettings.generated.h"

/**
 * 
 */
UCLASS(config=Game, DefaultConfig)
class KYRGYZFABLE_API UKyrgyzFableSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly)
	FString ParentalControlPassword = "123456";
};