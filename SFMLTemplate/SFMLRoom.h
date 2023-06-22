#ifndef SFMLROOM_H
#define SFMLROOM_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "QuadTree.h"
#include "SFMLGameObject.h"

class SFMLRoom
{
public:
	// Constructor
	SFMLRoom();

	// Destructor
	virtual ~SFMLRoom();

	// Update the room
	virtual void Update(const sf::Time & DeltaTime);

	// Draw the room
	virtual void Draw();

	// Insert an object into the room
	template <typename T>
	T * InstanceCreate(T * NewObject);

	// Remove an object from the room
	void InstanceDestroy(SFMLGameObject * ObjectToDestroy);

	// Alert engine that we need to resort the objects by depth
	void DepthOrderChangeMade();

	void QuitGameImmediately();

	bool ShouldQuitGame();

	template<typename T>
	bool CollisionPoint(const sf::Vector2f & Point);

	template<typename T>
	T *  GetObjectAtPoint(const sf::Vector2f & Point);
	
	template<typename T>
	bool PlaceMeeting(SFMLGameObject * Object, const sf::Vector2f & MoveToPoint);

	template<typename T>
	T *  InstancePlace(SFMLGameObject * Object, const sf::Vector2f & Point);

	template<typename T>
	std::vector<T *> GetAllGameObjectsOfType();

private:
	// The vector of game objects in the room
	std::vector<SFMLGameObject *> GameObjects;

	QuadTree * Tree;

	bool ReSortGameObjectsByDepth;

	bool ShouldQuitGameImmediately;

private:
	bool IsPointContained(const sf::Vector2f & Point, const sf::Rect<float> & Bounds);
};
template <typename T>
T * SFMLRoom::InstanceCreate(T * NewObject)
{
	// Just push it onto the vector
	NewObject->SetRoomCreatedIn(this);
	GameObjects.push_back(NewObject);
	Tree->AddGameObject(NewObject);
	return NewObject;
}

template<typename T>
bool SFMLRoom::CollisionPoint(const sf::Vector2f & Point)
{
	std::vector<SFMLGameObject *>::iterator iter = GameObjects.begin();
	for (; iter != GameObjects.end(); ++iter)
	{
		if (IsPointContained(Point, (*iter)->GetBoundingBox()) == true)
		{
			if (dynamic_cast<T *>(*iter) != nullptr)
			{
				return true;
			}
		}
	}

	return false;
}

template<typename T>
T * SFMLRoom::GetObjectAtPoint(const sf::Vector2f & Point)
{
	std::vector<SFMLGameObject *>::iterator iter = GameObjects.begin();
	for (; iter != GameObjects.end(); ++iter)
	{
		if (IsPointContained(Point, (*iter)->GetBoundingBox()) == true)
		{
			T * cast = dynamic_cast<T *>(*iter);
			if ( cast != nullptr)
			{
				return cast;
			}
		}
	}

	return nullptr;
}

template<typename T>
bool SFMLRoom::PlaceMeeting(SFMLGameObject * Object, const sf::Vector2f & MoveToPoint)
{
	// Move to location...
	sf::Vector2f OriginalPosition = Object->GetPosition();
	Object->SetPosition(MoveToPoint);

	// Get all colliding objects...
	std::vector<SFMLGameObject *> CollidedObjects = Tree->GetCollidingObjects(Object);

	// The vector holds all objects that collide with the current position
	std::vector<SFMLGameObject *>::iterator iter = CollidedObjects.begin();
	for (; iter != CollidedObjects.end(); ++iter)
	{
		// Check to see if any are of the T type we care about
		if (dynamic_cast<T *>(*iter) != nullptr)
		{
			// Move back to position before the check and return true
			Object->SetPosition(OriginalPosition);
			return true;
		}
	}

	// Move back to position before the check and return false
	Object->SetPosition(OriginalPosition);
	return false;
}

template<typename T>
T * SFMLRoom::InstancePlace(SFMLGameObject * Object, const sf::Vector2f & MoveToPoint)
{
	// Move to location...
	sf::Vector2f OriginalPosition = Object->GetPosition();
	Object->SetPosition(MoveToPoint);

	// Get all colliding objects...
	std::vector<SFMLGameObject *> CollidedObjects = Tree->GetCollidingObjects(Object);

	// The vector holds all objects that collide with the current position
	std::vector<SFMLGameObject *>::iterator iter = CollidedObjects.begin();
	for (; iter != CollidedObjects.end(); ++iter)
	{
		// Check to see if any are of the T type we care about
		T * cast = dynamic_cast<T *>(*iter);
		if ( cast != nullptr)
		{
			// Move back to position before the check and return true
			Object->SetPosition(OriginalPosition);
			return cast;
		}
	}

	// Move back to position before the check and return false
	Object->SetPosition(OriginalPosition);
	return nullptr;
}

template<typename T>
std::vector<T *> SFMLRoom::GetAllGameObjectsOfType()
{
	std::vector<T *> ToReturn;

	std::vector<SFMLGameObject *>::iterator iter = GameObjects.begin();
	for (; iter != GameObjects.end(); ++iter)
	{
		T * cast = dynamic_cast<T *>(*iter);
		if ( cast != nullptr)
		{
			ToReturn.push_back(cast);
		}
	}

	return ToReturn;
}

#endif