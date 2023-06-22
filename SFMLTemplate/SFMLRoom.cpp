#include "stdafx.h"
#include "QuadTree.h"
#include "ResourceManager.h"
#include "SFMLFont.h"
#include "SFMLGame.h"
#include "SFMLGameObject.h"
#include "SFMLRoom.h"

SFMLRoom::SFMLRoom()
	: GameObjects(),
	  ReSortGameObjectsByDepth(false),
	  ShouldQuitGameImmediately(false),
	  Tree( new QuadTree() )
{
	SFMLGame::GetInstance()->GetResourceManager()->LoadTexture("ASCIIFont", "ASCIIFont.png");
	SFMLGame::GetInstance()->GetResourceManager()->LoadTexture("1x1White", "1x1White.png");
}

SFMLRoom::~SFMLRoom()
{
	delete Tree;

	// Delete all game objects
	std::vector<SFMLGameObject *>::iterator iter = GameObjects.begin();
	for (; iter != GameObjects.end(); ++iter)
	{
		delete *iter;
	}
}

void SFMLRoom::Update(const sf::Time & DeltaTime)
{
	// Start fresh with possible depth order changes
	// GameObjects may flip this when they change depth order
	ReSortGameObjectsByDepth = false;

	// Pre-Update all game objects
	std::vector<SFMLGameObject *>::iterator iter = GameObjects.begin();
	for (; iter != GameObjects.end(); ++iter)
	{
		(*iter)->PreUpdate(DeltaTime);
		// fjkerkfjefkej
	}

	// Update all game objects
	iter = GameObjects.begin();
	for (; iter != GameObjects.end(); ++iter)
	{
		(*iter)->Update(DeltaTime);

		std::vector<SFMLGameObject *> CollidedObjects
							= Tree->GetCollidingObjects(*iter);
		for (std::size_t i = 0; i < CollidedObjects.size(); ++i)
		{
			(*iter)->OnCollision(CollidedObjects[i]);
			CollidedObjects[i]->OnCollision(*iter);
		}
	}
}

bool SortByDepth( SFMLGameObject * lhs, SFMLGameObject * rhs )
{
	return (lhs->GetDepth() < rhs->GetDepth());
}

void SFMLRoom::Draw()
{
	// Sort the vector only if we need to...
	if (ReSortGameObjectsByDepth == true)
	{
		std::sort(GameObjects.begin(), GameObjects.end(), SortByDepth);
	}

	// Draw all game objects
	std::vector<SFMLGameObject *>::iterator iter = GameObjects.begin();
	for (; iter != GameObjects.end(); ++iter)
	{
		(*iter)->Draw();
	}
}


void SFMLRoom::InstanceDestroy(SFMLGameObject * ObjectToDestroy)
{
	// Find it...
	std::vector<SFMLGameObject *>::iterator iter =
		std::find(GameObjects.begin(), GameObjects.end(), ObjectToDestroy);

	// Then maybe erase it...
	if (iter != GameObjects.end())
	{
		// Find faster way
		// Maybe swap the last element into this spot instead of
		// copying a ton of objects over one space
		GameObjects.erase(iter);
	}
}

void SFMLRoom::DepthOrderChangeMade()
{
	ReSortGameObjectsByDepth = true;
}

void SFMLRoom::QuitGameImmediately()
{
	ShouldQuitGameImmediately = true;
}

bool SFMLRoom::ShouldQuitGame()
{
	return ShouldQuitGameImmediately;
}

bool SFMLRoom::IsPointContained(const sf::Vector2f & Point, const sf::Rect<float> & Bounds)
{
	if ((Point.x >= Bounds.left) && (Point.x < (Bounds.left + Bounds.width)) &&
		(Point.y >= Bounds.top) && (Point.y < (Bounds.top + Bounds.height)))
	{
		return true;
	}

	return false;
}
