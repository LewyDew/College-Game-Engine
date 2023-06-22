#include "SFMLButton.h"
#include "SFMLMouse.h"

SFMLButton::SFMLButton( const std::string ResourceName,
	                    const sf::Vector2f & Position,
	                    void (*Callback)(SFMLGameObject *))
	: SFMLGameObject( ResourceName, Position.x, Position.y, 2, 1),
	  CallbackFunction(Callback)
{
	SetImageSpeed(0);
}

bool SFMLButton::IsPointContained(const sf::Vector2i & TestPoint)
{
	sf::Vector2f GP = GetPosition();

	if (TestPoint.x < GP.x)
		return false;

	if (TestPoint.x >= GP.x + GetSpriteWidth())
		return false;

	if (TestPoint.y < GP.y)
		return false;

	if (TestPoint.y >= GP.y + GetSpriteHeight())
		return false;

	return true;
}

void SFMLButton::Update(const sf::Time & DeltaTime)
{
	SFMLGameObject::Update(DeltaTime);

	SetImageIndex(0);
	if (IsPointContained(SFMLMouse::GetInstance()->GetPosition()))
	{
		SetImageIndex(1);
		if (SFMLMouse::GetInstance()->IsButtonPressed(SFMLMouse::LEFT))
		{
			CallbackFunction(this);
		}
	}

}