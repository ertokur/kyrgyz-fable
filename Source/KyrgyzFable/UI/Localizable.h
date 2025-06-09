// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Localizable.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class ULocalizable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class KYRGYZFABLE_API ILocalizable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Localizable)
	void UpdateLanguage();
};