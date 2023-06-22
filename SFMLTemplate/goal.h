#pragma once


#include "SFMLGameObject.h"


class goal :public SFMLGameObject
{
public:
	goal(const std::string & ResourceName,
		float XStart,
		float YStart,
		int HFrames = 1,
		int VFrames = 1);

	void Update(const sf::Time & DeltaTime);

	bool HasBox();

private:

};