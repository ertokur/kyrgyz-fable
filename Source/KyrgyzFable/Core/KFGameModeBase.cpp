// Erbol Tokur


#include "KyrgyzFable/Core/KFGameModeBase.h"

#include "KyrgyzFable/Core/KFPlayerCharacterBase.h"
#include "KyrgyzFable/Core/KFPlayerControllerBase.h"

AKFGameModeBase::AKFGameModeBase()
{
	DefaultPawnClass = AKFPlayerCharacterBase::StaticClass();
	PlayerControllerClass = AKFPlayerControllerBase::StaticClass();
}