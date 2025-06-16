// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "MissionStep_Base.h"
#include "MissionStep_Quiz.generated.h"

UCLASS()
class KYRGYZFABLE_API AMissionStep_Quiz : public AMissionStep_Base
{
	GENERATED_BODY()

public:
	AMissionStep_Quiz();

	virtual void Activate() override;
	virtual void Deactivate() override;
	virtual void CompleteStep() override;

	UFUNCTION(BlueprintPure)
	FORCEINLINE bool CanCollectData() const { return bCollectData; }

	UFUNCTION(BlueprintCallable)
	FQuizCollectableData CollectData() const;

	UFUNCTION(BlueprintCallable)
	void AddCorrectAnswerCount();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetTotalAnswers(int32 NewCount = 0);
	
private:
	UPROPERTY(EditInstanceOnly, Category = "Default|Settings")
	bool bCollectData = true;

	UPROPERTY(EditInstanceOnly, Category = "Default|Settings")
	FName QuizNameKey;

	UPROPERTY(EditInstanceOnly, Category = "Default|Settings", meta = (RequiredAssetDataTags  = "RowStructure=/Script/KyrgyzFable.LocalizationTableRow"))
	UDataTable* QuizNamesDataTable = nullptr;
	
	int32 CorrectAnswers = 0;
	int32 TotalAnswers = 0;
	float SolutionTime = 0.f;
	FDateTime CompleteDate;
};