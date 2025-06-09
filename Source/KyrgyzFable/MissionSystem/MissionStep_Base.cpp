// Erbol Tokur


#include "MissionStep_Base.h"

#include "Components/TextRenderComponent.h"

DEFINE_LOG_CATEGORY(LogMission);

AMissionStep_Base::AMissionStep_Base()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));
	TextRender = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextRender"));
	TextRender->SetupAttachment(RootComponent);
}

void AMissionStep_Base::BeginPlay()
{
	Super::BeginPlay();
	Deactivate();
	
#ifdef UE_BUILD_SHIPPING
	TextRender->DestroyComponent();
#endif
}

void AMissionStep_Base::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	TextRender->SetText(FText::FromName(ID));
}

void AMissionStep_Base::Activate()
{
	State = EMissionStepState::MSS_Active;
	UE_LOG(LogMission, Display, TEXT("[%s] - Step Activated"), *GetID().ToString());
}

void AMissionStep_Base::CompleteStep()
{
	Deactivate();
	State = EMissionStepState::MSS_Completed;
	UE_LOG(LogMission, Display, TEXT("[%s] - Step Completed"), *GetID().ToString());
	OnStepCompleted.Broadcast();
}

void AMissionStep_Base::Deactivate()
{
	State = EMissionStepState::MSS_NotActive;
	UE_LOG(LogMission, Display, TEXT("[%s] - Step Deactivated"), *GetID().ToString());
}