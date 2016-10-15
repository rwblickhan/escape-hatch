#pragma once
#include <Stage.h>

class NavigationInterface
{
public:
	NavigationInterface();
	~NavigationInterface();

	void Init();

	void MoveTo(Stage::Direction direction);


};
