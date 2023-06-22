#pragma once

#include <SFML/Graphics.hpp>

#include "SFMLGameObject.h"

class SFMLButton : public SFMLGameObject
{
public:
	SFMLButton(const std::string ResourceName,
			   const sf::Vector2f & Position,
		       void (*Callback)(SFMLGameObject *));

	virtual void Update(const sf::Time & DeltaTime);

private:
	bool IsPointContained(const sf::Vector2i & TestPoint);

	void (*CallbackFunction)(SFMLGameObject *);
};
