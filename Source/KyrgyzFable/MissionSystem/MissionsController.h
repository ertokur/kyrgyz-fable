// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MissionsController.generated.h"

UCLASS()
class KYRGYZFABLE_API AMissionsController : public AActor
{
	GENERATED_BODY()

public:
	AMissionsController();

protected:
	virtual void BeginPlay() override;
};