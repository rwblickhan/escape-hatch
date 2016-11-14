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

int main()
{
    UiManager* pUiManager = UiManager::Get();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    pUiManager->Deinit();
	return -1;
}
