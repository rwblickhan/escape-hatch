#include <GameManager.h>
#include <UiManager.h>
#include <Types.h>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

using namespace ui;
using namespace types;

UiManager* UiManager::pInstance = nullptr;
UiState uiState = UiState::UI_Invalid;
GameManager* GameManager::pInstance = nullptr;
GameState gameState = GameState::GS_Invalid;

int main()
{
    UiManager* pUiManager = UiManager::Get();
    pUiManager->Init(Screen_Loading);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    pUiManager->Deinit();
	return -1;
}
