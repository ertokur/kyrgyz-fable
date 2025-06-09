// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KyrgyzFableHelpers.generated.h"

/**
 * 
 */
UCLASS()
class KYRGYZFABLE_API UKyrgyzFableHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = KyrgyzFableHelpers)
	static FText GetLocalizationByKey(const UObject* WorldContext, const UDataTable* DataTable, const FName Key);

	UFUNCTION(BlueprintPure, Category = KyrgyzFableHelpers)
	static class UKFGameInstanceBase* GetKFGameInstance(const UObject* WorldContext);
};