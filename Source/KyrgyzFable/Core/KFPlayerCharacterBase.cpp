// Erbol Tokur

#include "KyrgyzFable/Core/KFPlayerCharacterBase.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "KyrgyzFable/Save/PlayerProgress.h"
#include "KyrgyzFable/Save/SaveSubsystem.h"

AKFPlayerCharacterBase::AKFPlayerCharacterBase()
{
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f;	
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

void AKFPlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	if (USaveSubsystem* SaveSubsystem = GetGameInstance()->GetSubsystem<USaveSubsystem>())
	{
		if (UPlayerProgress* PlayerProgress = SaveSubsystem->GetPlayerProgress())
		{
			SetActorLocation(PlayerProgress->PlayerLocation);
			SetActorRotation(PlayerProgress->PlayerRotation);
		}
	}
}

void AKFPlayerCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AKFPlayerCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &AKFPlayerCharacterBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AKFPlayerCharacterBase::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AKFPlayerCharacterBase::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AKFPlayerCharacterBase::LookUpAtRate);
	PlayerInputComponent->BindAction("Pause", IE_Pressed, this, &AKFPlayerCharacterBase::TogglePause).bExecuteWhenPaused = true;
}

void AKFPlayerCharacterBase::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AKFPlayerCharacterBase::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AKFPlayerCharacterBase::TogglePause()
{
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (PauseMenu)
		{
			UGameplayStatics::SetGamePaused(GetWorld(), false);
			PauseMenu->RemoveFromParent();
			PauseMenu = nullptr;
			PC->SetInputMode(FInputModeGameOnly());
			PC->SetShowMouseCursor(false);
		}
		else
		{
			UGameplayStatics::SetGamePaused(GetWorld(), true);
			
			if (PauseMenuClass)
			{
				PauseMenu = Cast<UPauseMenu>(CreateWidget(PC, PauseMenuClass));

				if (PauseMenu)
				{
					PauseMenu->AddToViewport();
					PauseMenu->OnPauseExit.AddDynamic(this, &AKFPlayerCharacterBase::TogglePause);
				}
			}
			
			PC->FlushPressedKeys();
			PC->SetInputMode(FInputModeGameAndUI());
			PC->SetShowMouseCursor(true);
		}
	}
}

void AKFPlayerCharacterBase::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AKFPlayerCharacterBase::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f) )
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}