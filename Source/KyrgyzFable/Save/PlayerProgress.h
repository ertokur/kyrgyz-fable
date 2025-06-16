// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "KyrgyzFable/KyrgyzFableTypes.h"
#include "PlayerProgress.generated.h"

/**
 * 
 */
UCLASS()
class KYRGYZFABLE_API UPlayerProgress : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = Save)
	FVector PlayerLocation;

	UPROPERTY(BlueprintReadOnly, Category = Save)
	FRotator PlayerRotation;

	UPROPERTY(BlueprintReadOnly, Category = Save)
	int32 LastCompletedMissionIndex = -1;

	UPROPERTY(BlueprintReadOnly, Category = Save)
	TArray<FQuizCollectableData> QuizCollectableData;
};