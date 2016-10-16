#include <GameManager.h>
#include <UiManager.h>
#include <Types.h>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

using namespace ui;

GameManager* GameManager::pInstance = nullptr;
types::GameState gameState = types::GameState::GS_Invalid;
UiManager* UiManager::pInstance = nullptr;
types::UiState uiState = types::UiState::UI_Invalid;

int main()
{
    GameManager* pGameManager = GameManager::Get();
    UiManager* pUiManager = UiManager::Get();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    pUiManager->Deinit();
	return -1;
}
