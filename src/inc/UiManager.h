#pragma once

#include <Types.h>
#include <SDL2/SDL.h>
#include <string>
#include <map>

namespace eh
{
    static std::map<Screen, std::string> ScreenToPathMap = {
        {Screen::Loading, "loading.bmp"}
    };



    //class that manages UI
    class UiManager
    {
    private:
        static std::unique_ptr<UiManager> pInstance;

        Error DisplayImg(std::string imgPath);

        std::string GetPath(Screen screen);

        //private constructor due to singleton
        UiManager();

        UiState uiState;

        SDL_Window* m_pWin;
        SDL_Renderer* m_pRen;
        SDL_Texture* m_pTempTex;

    public:

        //get singleton
        static std::unique_ptr<UiManager> Get()
    	{
    		if (!pInstance)
    		{
    			pInstance = std::unique_ptr<UiManager>(new UiManager());
    		}
    		return std::move(pInstance);
    	}

        ~UiManager();

        //initialize UI manager
        Error Init(Screen initScreen);

        //deinitialize UI manager
        Error Deinit();

        Error Render(std::string imgPath);
    };
}
