#pragma once
#include "SFMLGameObject.h"


class GoalChecker :public SFMLGameObject
{
public:
	GoalChecker(const std::string & ResourceName,
		float XStart,
		float YStart,
		int HFrames = 1,
		int VFrames = 1,
		int lv =0);

	void Update(const sf::Time & DeltaTime);

	bool HasBox();

	void SaveToFile();
	void ReadFile();
private:
	int level;
};