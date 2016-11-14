#include <UiManager.h>
#include <iostream>
#include <string>

using namespace ui;
using namespace types;

#ifdef _WIN32
    const char PATH_SEP = '\\';
#else
    const char PATH_SEP = '/';
#endif

UiManager::UiManager()
    : uiState(UI_Invalid)
    , m_pWin(nullptr)
    , m_pRen(nullptr)
    , m_pTempTex(nullptr)
{
}

UiManager::~UiManager()
{
}

Error UiManager::Init(Screen initScreen)
{
    uiState = UI_Initializing;
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "SDL_Init error: " << SDL_GetError() << std::endl;
        return Err_Init_Failed;
    }
    m_pWin = SDL_CreateWindow("Main Window", 100, 100, 640, 400, SDL_WINDOW_SHOWN);
    if (m_pWin == nullptr)
    {
        std::cout << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
        Deinit();
        return Err_Init_Failed;
    }
    m_pRen = SDL_CreateRenderer(m_pWin, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_pRen == nullptr)
    {
        std::cout << "SDL_CreateRenderer error: " << SDL_GetError() << std::endl;
        Deinit();
        return Err_Init_Failed;
    }

    DisplayImg(GetPath(initScreen));
    uiState = UI_Running;
    return Err_Success;
}

Error UiManager::Deinit()
{
    uiState = UI_Closing;
    if (m_pTempTex)
    {
        SDL_DestroyTexture(m_pTempTex);
    }
    if (m_pRen)
    {
        SDL_DestroyRenderer(m_pRen);
    }
    if (m_pWin)
    {
        SDL_DestroyWindow(m_pWin);
    }
    SDL_Quit();
    return Err_Success;
}

Error CallbackDisplayImg(std::string imgPath)
{
    return Err_Not_Implemented;
}

std::string UiManager::GetPath(Screen screen)
{
    std::string imgPath = SDL_GetBasePath();
    imgPath += "data";
    imgPath += PATH_SEP;
    imgPath += ScreenToPathMap[screen];
    return imgPath;
}

Error UiManager::DisplayImg(std::string imgPath)
{
    SDL_Surface* img = SDL_LoadBMP(imgPath.c_str());
    if (img == nullptr) {
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        Deinit();
        return Err_Init_Failed;
    }
    SDL_Texture* m_pTempTex = SDL_CreateTextureFromSurface(m_pRen, img);
    SDL_FreeSurface(img);
    if (m_pTempTex == nullptr) {
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        Deinit();
        return Err_Init_Failed;
    }
    SDL_RenderClear(m_pRen);
    SDL_RenderCopy(m_pRen, m_pTempTex, NULL, NULL);
    SDL_RenderPresent(m_pRen);
    return Err_Success;
}
