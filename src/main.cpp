#include <GameManager.h>
#include <UiManager.h>
#include <Types.h>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

using namespace eh;

GameState gameState = GameState::Invalid;
UiState uiState = UiState::Invalid;
std::unique_ptr<GameManager> GameManager::pInstance = std::unique_ptr<GameManager>(nullptr);
std::unique_ptr<UiManager> UiManager::pInstance = std::unique_ptr<UiManager>(nullptr);

int main()
{
    std::unique_ptr<GameManager> pGameManager = GameManager::Get();
    pGameManager->Init();
    std::this_thread::sleep_for(std::chrono::seconds(5));

	return -1;
}
