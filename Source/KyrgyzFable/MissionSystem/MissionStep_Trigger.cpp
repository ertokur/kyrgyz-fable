// Erbol Tokur


#include "MissionStep_Trigger.h"


AMissionStep_Trigger::AMissionStep_Trigger()
{
	TriggerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TriggerMesh"));
	SetRootComponent(TriggerMesh);
	TriggerMesh->SetCollisionResponseToAllChannels(ECR_Overlap);
	TriggerMesh->OnComponentBeginOverlap.AddDynamic(this, &AMissionStep_Trigger::OnTriggered);
}

void AMissionStep_Trigger::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMissionStep_Trigger::OnTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}