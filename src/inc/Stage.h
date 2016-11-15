#pragma once
#include <string>
#include <map>
#include <Item.h>

namespace eh
{
	class Stage
	{
	public:

		enum struct Direction
		{
			// Directions to move onto different stages movement
			Back,
			Up,
			Down,
			Left,
			Right,
			CenterZoom,
			AltZoom
		};

		enum struct Locale
		{
			// Interactions in the current stage, should not need more than 5
			Left,
			Right,
			Up,
			Down,
			Center
		};

		int							id;
		std::string					name;
		std::map<Direction, Stage*>	pstages;  //!< Stages that we are connected to
		std::map<Locale, Item*>		pitems;	  //!< Items that are interactive

		// Graphics


	public:
		Stage();
		~Stage();
	};
}
