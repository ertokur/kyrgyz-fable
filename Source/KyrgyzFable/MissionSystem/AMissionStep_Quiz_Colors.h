// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "MissionStep_Quiz.h"
#include "AMissionStep_Quiz_Colors.generated.h"

UCLASS()
class KYRGYZFABLE_API AAMissionStep_Quiz_Colors : public AMissionStep_Quiz
{
	GENERATED_BODY()

public:
	AAMissionStep_Quiz_Colors();

protected:
	virtual void BeginPlay() override;
};