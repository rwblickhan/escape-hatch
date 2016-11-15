#pragma once
namespace eh
{
    enum struct GameState
    {
        Invalid = -1,
        Initializing,
        Running,
        Closing
    };

    enum struct UiState
    {
        Invalid = -1,
        Initializing,
        Running,
        Closing
    };

    enum struct Error
    {
        Success = 0,
        Init_Failed,
        Not_Implemented
    };

    enum struct Screen
    {
        Loading = 0
    };
}
