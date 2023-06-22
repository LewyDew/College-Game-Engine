#include "QuadTree.h"
#include "SFMLGameObject.h"

QuadTree::QuadTree()
	: UPPER_LEFT( nullptr ),
	  UPPER_RIGHT( nullptr ),
	  LOWER_LEFT( nullptr ),
	  LOWER_RIGHT( nullptr ),
	  Bounds( -200, -200, 2000, 2000 ),
	  GameObjects()
{
	// Nothing here...
}

sf::Rect<float> QuadTree::GetBoundingBox()
{
	return Bounds;
}

void QuadTree::AddGameObject(SFMLGameObject * Object)
{
	GameObjects.push_back(Object);
}

std::vector<SFMLGameObject *> QuadTree::GetCollidingObjects(SFMLGameObject * Object)
{
	std::vector<SFMLGameObject *> ToReturn;

	std::vector<SFMLGameObject *>::iterator iter = GameObjects.begin();
	for (; iter != GameObjects.end(); ++iter)
	{
		if (Object != *iter)
		{ 
			if (DoBoundingBoxesCollide(Object->GetBoundingBox(), (*iter)->GetBoundingBox()))
			{
				ToReturn.push_back(*iter);
			}
		}
	}
	
	return ToReturn;
}

bool QuadTree::DoBoundingBoxesCollide(const sf::Rect<float> & lhs,
									  const sf::Rect<float> & rhs)
{
	float LHS_LEFT = lhs.left;
	float RHS_LEFT = rhs.left;
	float LHS_TOP = lhs.top;
	float RHS_TOP = rhs.top;
	float LHS_RIGHT = lhs.left + lhs.width - 0.0001;
	float RHS_RIGHT = rhs.left + rhs.width - 0.0001;
	float LHS_BOTTOM = lhs.top + lhs.height - 0.0001;
	float RHS_BOTTOM = rhs.top + rhs.height - 0.0001;

	if (LHS_RIGHT < RHS_LEFT)
		return false;

	if (RHS_RIGHT < LHS_LEFT)
		return false;

	if (LHS_BOTTOM < RHS_TOP)
		return false;

	if (RHS_BOTTOM < LHS_TOP)
		return false;

	return true;
}