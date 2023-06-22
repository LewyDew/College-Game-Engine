#pragma once
#include "SFMLGameObject.h"

class Player : public SFMLGameObject
{
public:
	Player(const std::string & ResourceName,
		float XStart,
		float YStart,
		int HFrames,
		int VFrames);

	int getScore();
	void Update(const sf::Time & DeltaTime);
private:
	int Score;
};