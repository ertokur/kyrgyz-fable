// Erbol Tokur


#include "MissionStep_Dialog.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AMissionStep_Dialog::AMissionStep_Dialog()
{
	PartnerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PartnerMesh"));
	PartnerMesh->SetupAttachment(RootComponent);

	DialogCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("DialogCamera"));
	DialogCamera->SetupAttachment(RootComponent);
}

void AMissionStep_Dialog::BeginPlay()
{
	Super::BeginPlay();
}

void AMissionStep_Dialog::Activate()
{
	Super::Activate();

	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		PlayerController->SetViewTargetWithBlend(this, BlendTime);

		if (DialogScreenWidgetClass)
		{
			DialogScreen = Cast<UDialogScreen>(CreateWidget(PlayerController, DialogScreenWidgetClass));

			if (DialogScreen)
			{
				DialogScreen->DialogDataTable = DialogDataTable;
				DialogScreen->AddToViewport();

				if (ACharacter* Character = Cast<ACharacter>(PlayerController->GetPawn()))
				{
					Character->GetCharacterMovement()->StopMovementImmediately();
				}

				PlayerController->FlushPressedKeys();
				PlayerController->SetInputMode(FInputModeUIOnly());
				PlayerController->SetShowMouseCursor(true);
				DialogScreen->OnDialogCompleted.AddDynamic(this, &AMissionStep_Base::CompleteStep);
			}
		}
	}
}

void AMissionStep_Dialog::Deactivate()
{
	Super::Deactivate();

	if (DialogScreen)
	{
		DialogScreen->RemoveFromParent();
		DialogScreen = nullptr;
		
		if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
		{
			PlayerController->SetInputMode(FInputModeGameOnly());
			PlayerController->SetShowMouseCursor(false);
			PlayerController->SetViewTarget(PlayerController->GetPawn());
		}
	}
}