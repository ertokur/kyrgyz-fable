// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SaveSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class KYRGYZFABLE_API USaveSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	USaveSubsystem();

	UFUNCTION(BlueprintCallable, Category = Save)
	void SaveSettings();

	UFUNCTION(BlueprintCallable, Category = Save)
	void SaveProgress(const AMissionsController* MissionsController);

	UFUNCTION(BlueprintCallable, Category = Save)
	void ClearProgress();
	
	UFUNCTION(BlueprintPure, Category = Save)
	UPlayerSettings* GetPlayerSettings();

	UFUNCTION(BlueprintPure, Category = Save)
	UPlayerProgress* GetPlayerProgress();
	
protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

private:
	UPROPERTY()
	mutable UPlayerSettings* PlayerSettings = nullptr;

	UPROPERTY()
	mutable UPlayerProgress* PlayerProgress = nullptr;

	UPlayerSettings* TryLoadSettings();

	UPlayerProgress* TryLoadProgress();
};