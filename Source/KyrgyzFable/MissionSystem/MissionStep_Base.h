// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MissionStep_Base.generated.h"

UCLASS()
class KYRGYZFABLE_API AMissionStep_Base : public AActor
{
	GENERATED_BODY()

public:
	AMissionStep_Base();

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = Settings)
	FName ID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	class UTextRenderComponent* TextRender = nullptr;
	
protected:
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
};