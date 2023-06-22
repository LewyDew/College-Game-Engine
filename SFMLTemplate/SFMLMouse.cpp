#include <SFML/Graphics.hpp>

#include "SFMLGame.h"
#include "SFMLMouse.h"

SFMLMouse * SFMLMouse::Instance = nullptr;

SFMLMouse::SFMLMouse()
	//: PreviousStatus(),
	//CurrentStatus()
{
	for (int i = 0; i < 5; ++i)
	{
		PreviousStatus.push_back(false);
		CurrentStatus.push_back(false);
	}
}

SFMLMouse * SFMLMouse::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new SFMLMouse();
	}

	return Instance;
}

void SFMLMouse::Update()
{
	for (int i = 0; i < 5; ++i)
	{
		PreviousStatus[i] = CurrentStatus[i];
	}

	CurrentStatus[LEFT] = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	CurrentStatus[MIDDLE] = sf::Mouse::isButtonPressed(sf::Mouse::Middle);
	CurrentStatus[RIGHT] = sf::Mouse::isButtonPressed(sf::Mouse::Right);
	CurrentStatus[X1] = sf::Mouse::isButtonPressed(sf::Mouse::XButton1);
	CurrentStatus[X2] = sf::Mouse::isButtonPressed(sf::Mouse::XButton2);
}

bool SFMLMouse::IsButtonPressed(SFMLMouse::Buttons Button)
{
	return (CurrentStatus[static_cast<int>(Button)] == true) &&
		   ((PreviousStatus[static_cast<int>(Button)] == false));
}

bool SFMLMouse::IsButtonDown(SFMLMouse::Buttons Button)
{
	return (CurrentStatus[static_cast<int>(Button)] == true) &&
		((PreviousStatus[static_cast<int>(Button)] == true));
}

bool SFMLMouse::IsButtonReleased(SFMLMouse::Buttons Button)
{
	return (CurrentStatus[static_cast<int>(Button)] == false) &&
		((PreviousStatus[static_cast<int>(Button)] == true));
}

bool SFMLMouse::IsButtonUp(SFMLMouse::Buttons Button)
{
	return (CurrentStatus[static_cast<int>(Button)] == false) &&
		((PreviousStatus[static_cast<int>(Button)] == false));
}

sf::Vector2i SFMLMouse::GetPosition()
{
	return sf::Mouse::getPosition( *SFMLGame::GetInstance()->GetWindow());
}

void SFMLMouse::SetPosition(const sf::Vector2i & Value)
{
	sf::Mouse::setPosition(Value);
}

void SFMLMouse::SetPosition(int X, int Y)
{
	SetPosition(sf::Vector2i(X, Y));
}

void SFMLMouse::SetPositionX(int Value)
{
	SetPosition(sf::Vector2i(Value, GetPosition().y));
}

void SFMLMouse::SetPositionY(int Value)
{
	SetPosition(sf::Vector2i(GetPosition().x, Value));
}
