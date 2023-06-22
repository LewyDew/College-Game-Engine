#include "ResourceManager.h"
#include "SFMLFont.h"
#include "SFMLGame.h"
#include "SFMLGameObject.h"
#include "SFMLMouse.h"
#include "SFMLRoom.h"
#include "Player.h"
#include "SFMLKeyboard.h"
#include "Solid.h"
#include "SFMLBox.h"
#include "goal.h"
#include <vector>
goal::goal(const std::string & ResourceName,
	float XStart,
	float YStart,
	int HFrames,
	int VFrames)
	:SFMLGameObject(ResourceName,
		XStart,
		YStart,
		HFrames,
		VFrames)
{

}


void goal::Update(const sf::Time & DeltaTime)
{
	//(new std::vector<goal> *goals->SFMLGameObject::GetAllGameObjectsOfType<goal>();
}

bool goal::HasBox()
{
	return (SFMLGameObject::PlaceMeeting<SFMLBox>(sf::Vector2f(this->GetPreviousPositionX(), this->GetPreviousPositionY())));
}