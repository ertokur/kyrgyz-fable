// Erbol Tokur


#include "MissionStep_Trigger.h"


AMissionStep_Trigger::AMissionStep_Trigger()
{
	TriggerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TriggerMesh"));
	TriggerMesh->SetupAttachment(RootComponent);
	TriggerMesh->SetCollisionResponseToAllChannels(ECR_Overlap);
	TriggerMesh->OnComponentBeginOverlap.AddDynamic(this, &AMissionStep_Trigger::OnTriggered);
}

void AMissionStep_Trigger::Activate()
{
	Super::Activate();
	TriggerMesh->SetHiddenInGame(false);
	TriggerMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AMissionStep_Trigger::Deactivate()
{
	Super::Deactivate();
	TriggerMesh->SetHiddenInGame(true);
	TriggerMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AMissionStep_Trigger::BeginPlay()
{
	Super::BeginPlay();
}

void AMissionStep_Trigger::OnTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CompleteStep();
}