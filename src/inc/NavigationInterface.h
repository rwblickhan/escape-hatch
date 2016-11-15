#pragma once
#include <Stage.h>

namespace eh
{
	class NavigationInterface
	{
	public:
		NavigationInterface();
		~NavigationInterface();

		void Init();

		void MoveTo(Stage::Direction direction);


	};
}
