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
		GS_Invalid = -1,
		GS_Initializing,
		GS_Running,
		GS_Closing
	};

	GameState gameState;
	static GameManager* instance;
	std::mutex m_mutex;
	InventoryInterface m_inventoryInterface;
	NavigationInterface m_navigationInterface;
	InputHandler m_inputHandler;
	
	GameManager() {	Clear(); }
	~GameManager() { Clear(); }

public:
	void Clear()
	{
		m_inventoryInterface.init();
		m_navigationInterface.init();
	}

	static GameManager* Get()
	{
		if (!instance)
		{
			instance = new GameManager();
		}
		return instance;
	}

	InventoryInterface* getInventoryInterface()
	{
		return &m_inventoryInterface;
	}

	NavigationInterface* getNavigationInterface()
	{
		return &m_navigationInterface;
	}

	void Process();
};
