#include <GameManager.h>
#include <UiManager.h>
#include <Types.h>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

using namespace eh;

UiManager* UiManager::pInstance = nullptr;
UiState uiState = UiState::Invalid;
GameManager* GameManager::pInstance = nullptr;
GameState gameState = GameState::Invalid;

int main()
{
    UiManager* pUiManager = UiManager::Get();
    pUiManager->Init(Screen::Loading);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    pUiManager->Deinit();
	return -1;
}
