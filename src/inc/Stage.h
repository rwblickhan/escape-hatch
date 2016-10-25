#pragma once
#include <string>
#include <map>
#include <Item.h>

class Stage
{
public:

	enum Direction
	{
		// Directions to move onto different stages movement
		D_Back,
		D_Up,
		D_Down,
		D_Left,
		D_Right,
		D_CenterZoom,
		D_AltZoom
	};

	enum Locale
	{
		// Interactions in the current stage, should not need more than 5
		L_Left,
		L_Right,
		L_Up,
		L_Down,
		L_Center
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
