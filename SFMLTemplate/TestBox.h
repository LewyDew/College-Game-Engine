#pragma once

#include "SFMLGameObject.h"

class TestBox : public SFMLGameObject
{
public:
	TestBox(float X, float Y);

	virtual void Update(const sf::Time & DeltaTime);
	virtual void Draw();
	virtual void OnCollision(SFMLGameObject * Object);

private:

};