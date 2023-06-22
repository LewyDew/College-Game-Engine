#pragma once



#include "Solid.h"
class SFMLWall :public Solid
{
public:
	SFMLWall(const std::string & ResourceName,
		float XStart,
		float YStart,
		int HFrames = 1,
		int VFrames = 1);

};
