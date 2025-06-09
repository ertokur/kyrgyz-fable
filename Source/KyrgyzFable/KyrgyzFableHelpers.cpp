// Erbol Tokur


#include "KyrgyzFableHelpers.h"

#include "KyrgyzFableTypes.h"
#include "Core/KFGameInstanceBase.h"
#include "Engine/DataTable.h"
#include "Kismet/GameplayStatics.h"

FText UKyrgyzFableHelpers::GetLocalizationByKey(const UObject* WorldContext, const UDataTable* DataTable, const FName Key)
{
	if (DataTable)
	{
		if (FLocalizationTableRow* Localization = DataTable->FindRow<FLocalizationTableRow>(Key, ""))
		{
			if (UKFGameInstanceBase* GameInstance = Cast<UKFGameInstanceBase>(UGameplayStatics::GetGameInstance(WorldContext)))
			{
				switch (GameInstance->GetLanguage())
				{
				case ELanguage::L_Russian:
					return Localization->Localization.Russian;
				case ELanguage::L_Kyrgyz:
					return Localization->Localization.Kyrgyz;
				case ELanguage::L_English:
					return Localization->Localization.English;
				}
			}
		}
	}

	return FText();
}

UKFGameInstanceBase* UKyrgyzFableHelpers::GetKFGameInstance(const UObject* WorldContext)
{
	if (UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(WorldContext))
	{
		return Cast<UKFGameInstanceBase>(GameInstance);
	}
	
	return nullptr;
}