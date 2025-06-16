// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "KyrgyzFable/KyrgyzFableTypes.h"
#include "PlayerSettings.generated.h"

/**
 * 
 */
UCLASS()
class KYRGYZFABLE_API UPlayerSettings : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = Save)
	ELanguage Language = ELanguage::L_Russian;
};