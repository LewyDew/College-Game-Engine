#pragma once

#include "SFMLGameObject.h"

class Solid: public SFMLGameObject
{
public:
	Solid(const std::string & ResourceName,
		float XStart,
		float YStart,
		int HFrames,
		int VFrames);
private:
};