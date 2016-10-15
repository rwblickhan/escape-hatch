#include <GameManager.h>
#include <string>
#include <iostream>

GameManager* GameManager::instance = nullptr;

int main()
{
    GameManager* gameManager = GameManager::Get();
	while (true) 
	{
	    std::cout << "hi" << std::endl;	
	}
	return -1;
}
