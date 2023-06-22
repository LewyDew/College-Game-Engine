#pragma once

#include "Solid.h"


class SFMLBox :public Solid
{
public:
	SFMLBox(const std::string & ResourceName,
		float XStart,
		float YStart,
		int HFrames = 1,
		int VFrames = 1);

	//void Update(const sf::Time & DeltaTime);

private:
	
};