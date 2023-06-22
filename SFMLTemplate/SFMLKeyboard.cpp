#include <SFML/Graphics.hpp>

#include "SFMLKeyboard.h"

SFMLKeyboard * SFMLKeyboard::Instance = nullptr;

SFMLKeyboard::SFMLKeyboard()
	: PreviousStatus(),
	  CurrentStatus()
{
	for (int i = 0; i < 150; ++i)
	{
		PreviousStatus.push_back(false);
		CurrentStatus.push_back(false);
	}
}

SFMLKeyboard * SFMLKeyboard::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new SFMLKeyboard();
	}

	return Instance;
}

void SFMLKeyboard::Update()
{
	for (int i = 0; i < 150; ++i)
	{
		PreviousStatus[i] = CurrentStatus[i];
		
		CurrentStatus[i] = 
			sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i));
	}
}

bool SFMLKeyboard::IsKeyPressed(sf::Keyboard::Key Key)
{
	return (CurrentStatus[static_cast<int>(Key)] == true) &&
		   ((PreviousStatus[static_cast<int>(Key)] == false));
}

bool SFMLKeyboard::IsKeyDown(sf::Keyboard::Key Key)
{
	return (CurrentStatus[static_cast<int>(Key)] == true) &&
		   ((PreviousStatus[static_cast<int>(Key)] == true));
}

bool SFMLKeyboard::IsKeyReleased(sf::Keyboard::Key Key)
{
	return (CurrentStatus[static_cast<int>(Key)] == false) &&
    	   ((PreviousStatus[static_cast<int>(Key)] == true));
}

bool SFMLKeyboard::IsKeyUp(sf::Keyboard::Key Key)
{
	return (CurrentStatus[static_cast<int>(Key)] == false) &&
   		   ((PreviousStatus[static_cast<int>(Key)] == false));

}