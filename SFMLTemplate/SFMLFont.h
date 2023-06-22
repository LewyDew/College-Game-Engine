#pragma once

#include "SFMLGameObject.h"

class SFMLFont : public SFMLGameObject
{
public:
	SFMLFont(const std::string & ResourceName);

	void DrawString(float X, float Y, const std::string & Text, const sf::Color & Color);

private:
	virtual void Draw();
	virtual void Update(const sf::Time & DeltaTime);
};