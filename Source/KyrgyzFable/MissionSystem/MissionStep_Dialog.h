// Erbol Tokur

#pragma once

#include "CoreMinimal.h"
#include "MissionStep_Base.h"
#include "KyrgyzFable/UI/DialogScreen.h"
#include "MissionStep_Dialog.generated.h"

UCLASS()
class KYRGYZFABLE_API AMissionStep_Dialog : public AMissionStep_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = MissionStep)
	USkeletalMeshComponent* PartnerMesh = nullptr;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = MissionStep)
	class UCameraComponent* DialogCamera = nullptr;

	virtual void Activate() override;
	
	virtual void Deactivate() override;

	AMissionStep_Dialog();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditInstanceOnly, Category = "Default|Settings")
	UDataTable* DialogDataTable = nullptr;

	UPROPERTY(EditInstanceOnly, Category = "Default|Settings")
	TSubclassOf<UDialogScreen> DialogScreenWidgetClass = nullptr;

	UPROPERTY(EditInstanceOnly, Category = "Default|Settings")
	float BlendTime = .5f;
	
	UPROPERTY()
	UDialogScreen* DialogScreen = nullptr;
};