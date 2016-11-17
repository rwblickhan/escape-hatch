#include <GameManager.h>

using namespace eh;

Error GameManager::Init()
{
    m_pUiManager = UiManager::Get();
    m_pUiManager->Init(Screen::Loading);

    return Error::Success;
}
