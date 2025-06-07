// Erbol Tokur


#include "MissionStep_Base.h"

#include "Components/TextRenderComponent.h"


AMissionStep_Base::AMissionStep_Base()
{
	PrimaryActorTick.bCanEverTick = false;
	TextRender = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextRender"));
	TextRender->SetupAttachment(RootComponent);
	
#ifdef UE_BUILD_SHIPPING
	TextRender->SetHiddenInGame(true);
#endif
}

void AMissionStep_Base::BeginPlay()
{
	Super::BeginPlay();
}

void AMissionStep_Base::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	TextRender->SetText(FText::FromName(ID));
}