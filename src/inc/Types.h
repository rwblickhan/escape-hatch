#pragma once

#include <map>

namespace types
{

    enum GameState
    {
    	GS_Invalid = -1,
    	GS_Initializing,
    	GS_Running,
    	GS_Closing
    };

    enum UiState
    {
        UI_Invalid = -1,
        UI_Initializing,
        UI_Running,
        UI_Closing
    };

    enum Error
    {
        Err_Success = 0,
        Err_Init_Failed,
        Err_Not_Implemented
    };

    enum Screen
    {
        Screen_Loading = 0
    };

}
