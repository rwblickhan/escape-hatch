#pragma once

#include <Types.h>
#include <SDL2/SDL.h>
#include <string>
#include <map>

using namespace types;

static std::map<Screen, std::string> ScreenToPathMap = {
    {Screen_Loading, "loading.bmp"}
};

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
    Error Init(Screen initScreen);

    //deinitialize UI manager
    Error Deinit();

    Error CallbackDisplayImg(std::string imgPath);

private:

    Error DisplayImg(std::string imgPath);

    std::string GetPath(Screen screen);

    //private constructor due to singleton
    UiManager();

    UiState uiState;
	static UiManager* pInstance;

    SDL_Window* m_pWin;
    SDL_Renderer* m_pRen;
    SDL_Texture* m_pTempTex;
};

}
