#pragma once

#include <InventoryInterface.h>
#include <NavigationInterface.h>
#include <InputHandler.h>
#include <Types.h>
#include <UiManager.h>

namespace eh
{
	class GameManager
	{
		// GameManger Singleton

		static GameState gameState;
		static std::unique_ptr<GameManager> pInstance;

		std::unique_ptr<UiManager> m_pUiManager;
		InventoryInterface m_inventoryInterface;
		NavigationInterface m_navigationInterface;
		InputHandler m_inputHandler;

		GameManager() {	Clear(); }

	public:

		Error Init();

        void GameLoop();

		void Clear()
		{
			m_inventoryInterface.Init();
			m_navigationInterface.Init();
		}

		static std::unique_ptr<GameManager> Get()
		{
			if (!pInstance)
			{
				pInstance = std::unique_ptr<GameManager>(new GameManager());
			}
			return std::move(pInstance);
		}

		InventoryInterface* GetInventoryInterface()
		{
			return &m_inventoryInterface;
		}

		NavigationInterface* GetNavigationInterface()
		{
			return &m_navigationInterface;
		}

        ~GameManager() { Clear(); }
	};
}
