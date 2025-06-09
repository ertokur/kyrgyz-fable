// Erbol Tokur


#include "KyrgyzFable/Core/KFGameInstanceBase.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "KyrgyzFable/UI/Localizable.h"

void UKFGameInstanceBase::SetLanguage(const ELanguage NewLanguage)
{
	Language = NewLanguage;
	
	TArray<UUserWidget*> OutWidgets;
	UWidgetBlueprintLibrary::GetAllWidgetsWithInterface(this, OutWidgets, ULocalizable::StaticClass(), false);

	for (const auto& Iter : OutWidgets)
	{
		if (Iter->Implements<ULocalizable>())
		{
			ILocalizable::Execute_UpdateLanguage(Iter);
		}
	}
}