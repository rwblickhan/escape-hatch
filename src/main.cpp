#include <GameManager.h>
#include <UiManager.h>
#include <Types.h>
#include <string>
#include <iostream>

using namespace ui;

GameManager* GameManager::pInstance = nullptr;
types::GameState gameState = types::GameState::GS_Invalid;
UiManager* UiManager::pInstance = nullptr;
types::UiState uiState = types::UiState::UI_Invalid;

int main()
{
    GameManager* pGameManager = GameManager::Get();
    UiManager* pUiManager = UiManager::Get();
	while (true)
	{
	    std::cout << "hi" << std::endl;
	}
	return -1;
}
