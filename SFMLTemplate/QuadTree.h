#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

class SFMLGameObject;

class QuadTree
{
public:
	QuadTree();

	sf::Rect<float> GetBoundingBox();

	void AddGameObject( SFMLGameObject * Object );

	std::vector<SFMLGameObject *> GetCollidingObjects( SFMLGameObject * Object );

	bool DoBoundingBoxesCollide(const sf::Rect<float> & lhs,
		                        const sf::Rect<float> & rhs);

private:
	QuadTree * UPPER_LEFT;
	QuadTree * UPPER_RIGHT;
	QuadTree * LOWER_LEFT;
	QuadTree * LOWER_RIGHT;

	sf::Rect<float> Bounds;

	std::vector<SFMLGameObject *> GameObjects;
};