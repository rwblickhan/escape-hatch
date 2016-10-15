#pragma once
#include <Stage.h>

class NavigationInterface
{
public:
	NavigationInterface();
	~NavigationInterface();

	void init();

	void MoveTo(Stage::Direction direction);


};

