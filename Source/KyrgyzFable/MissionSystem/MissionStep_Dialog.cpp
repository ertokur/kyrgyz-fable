// Erbol Tokur


#include "MissionStep_Dialog.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

AMissionStep_Dialog::AMissionStep_Dialog()
{
	PartnerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PartnerMesh"));
	PartnerMesh->SetCollisionResponseToAllChannels(ECR_Block);
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

	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		PC->SetViewTargetWithBlend(this, BlendTime);

		if (DialogScreenWidgetClass)
		{
			DialogScreen = Cast<UDialogScreen>(CreateWidget(PC, DialogScreenWidgetClass));

			if (DialogScreen)
			{
				DialogScreen->DialogDataTable = DialogDataTable;
				DialogScreen->AddToViewport();
				
				if (ACharacter* Character = Cast<ACharacter>(PC->GetPawn()))
				{
					Character->GetCharacterMovement()->StopMovementImmediately();
	
					if (bRotateToPartner)
					{
						FRotator ResultRotation = UKismetMathLibrary::FindLookAtRotation(Character->GetActorLocation(), PartnerMesh->GetComponentLocation());
						Character->SetActorRotation(ResultRotation);
					}
				}

				PC->FlushPressedKeys();
				PC->SetInputMode(FInputModeUIOnly());
				PC->SetShowMouseCursor(true);
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