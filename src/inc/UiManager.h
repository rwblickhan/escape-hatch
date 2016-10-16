#pragma once

#include <Types.h>
#include <SDL2/SDL.h>

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

    types::Error Init();
    types::Error Deinit();
private:
    UiManager();
    ~UiManager();

    //UiManager singleton
    static types::UiState uiState;
	static UiManager* pInstance;

    SDL_Window* m_pWin;
    SDL_Renderer* m_pRen;
    SDL_Texture* m_pTempTex;
};

}
