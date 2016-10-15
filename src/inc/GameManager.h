#pragma once
#include <thread>
#include <mutex>
#include <InventoryInterface.h>
#include <NavigationInterface.h>
#include <InputHandler.h>

class GameManager
{
	// GameManger Singleton
	enum GameState
	{
		Invalid = -1,
		Initializing,
		Running,
		Closing
	};

	GameState gameState;
	static GameManager* pInstance;
	std::mutex m_mutex;
	InventoryInterface m_inventoryInterface;
	NavigationInterface m_navigationInterface;
	InputHandler m_inputHandler;

	GameManager() {	Clear(); }
	~GameManager() { Clear(); }

public:
	void Clear()
	{
		m_inventoryInterface.Init();
		m_navigationInterface.Init();
	}

	static GameManager* Get()
	{
		if (!pInstance)
		{
			pInstance = new GameManager();
		}
		return pInstance;
	}

	InventoryInterface* GetInventoryInterface()
	{
		return &m_inventoryInterface;
	}

	NavigationInterface* GetNavigationInterface()
	{
		return &m_navigationInterface;
	}

	void Process();
};
