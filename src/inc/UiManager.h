#pragma once

#include <Types.h>
#include <SDL2/SDL.h>
#include <string>

using namespace types;

//namespace for ui-related code
namespace ui
{

//class that manages UI
class UiManager
{
public:

    //get singleton
    static UiManager* Get()
	{
		if (!pInstance)
		{
			pInstance = new UiManager();
		}
		return pInstance;
	}

    ~UiManager();

    //initialize UI manager
    Error Init();

    //deinitialize UI manager
    Error Deinit();

    Error CallbackDisplayImg(std::string imgPath);

private:

    //for internal/testing use only
    //for external use refer to CallbackDisplayImg
    Error TestDisplayImg(std::string imgPath);

    //private constructor due to singleton
    UiManager();

    UiState uiState;
	static UiManager* pInstance;

    SDL_Window* m_pWin;
    SDL_Renderer* m_pRen;
    SDL_Texture* m_pTempTex;
};

}
