// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "KyrgyzFable/KyrgyzFableTypes.h"
#include "KFGameInstanceBase.generated.h"

/**
 * 
 */
UCLASS()
class KYRGYZFABLE_API UKFGameInstanceBase : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = Localization)
	FORCEINLINE ELanguage GetLanguage() const { return Language; }

	UFUNCTION(BlueprintCallable, Category = Localization)
	void SetLanguage(const ELanguage NewLanguage);
	
private:
	ELanguage Language = ELanguage::L_Russian;
};