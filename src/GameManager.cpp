#include <GameManager.h>

using namespace eh;

Error GameManager::Init()
{
    m_pUiManager = UiManager::Get();
    m_pUiManager->Init(Screen::Loading);

    return Error::Success;
}

void GameManager::GameLoop()
{
    bool running = true;
    SDL_Event event;
    while (running)
    {
        m_pUiManager->Render(Screen::Loading/*TODO process here*/);
        while (SDL_PollEvent(&event))
        {
            if (SDL_KEYDOWN == event.type)
            {
                if (SDLK_ESCAPE == event.key.keysym.sym)
                {
                    running = false;
                    break;
                }
            }
        }
    }
    m_pUiManager->Deinit();
}