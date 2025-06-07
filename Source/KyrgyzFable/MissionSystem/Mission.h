// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mission.generated.h"

UCLASS()
class KYRGYZFABLE_API AMission : public AActor
{
	GENERATED_BODY()

public:
	AMission();

protected:
	virtual void BeginPlay() override;
};