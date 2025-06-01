// Erbol Tokur


#include "KyrgyzFable/Public/Core/KFGameModeBase.h"

#include "KyrgyzFable/Public/Core/KFPlayerCharacterBase.h"
#include "KyrgyzFable/Public/Core/KFPlayerControllerBase.h"

AKFGameModeBase::AKFGameModeBase()
{
	DefaultPawnClass = AKFPlayerCharacterBase::StaticClass();
	PlayerControllerClass = AKFPlayerControllerBase::StaticClass();
}