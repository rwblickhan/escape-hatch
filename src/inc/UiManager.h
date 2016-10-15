#pragma once

#include <Types.h>

namespace ui
{

class UiManager
{
public:
    static UiManager* Get()
	{
		if (!pInstance)
		{
			pInstance = new UiManager();
		}
		return pInstance;
	}
private:
    // UiManager Singleton

	static types::UiState uiState;
	static UiManager* pInstance;

    UiManager();
    ~UiManager();
};

}
