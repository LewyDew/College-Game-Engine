#pragma once

#include <vector>

class SFMLKeyboard
{
public:
	static SFMLKeyboard * GetInstance();
	
	void Update();

	bool IsKeyPressed(sf::Keyboard::Key Key);
	bool IsKeyDown(sf::Keyboard::Key Key);
	bool IsKeyReleased(sf::Keyboard::Key Key);
	bool IsKeyUp(sf::Keyboard::Key Key);

private:
	SFMLKeyboard();

	static SFMLKeyboard * Instance;

	std::vector<bool> PreviousStatus;
	std::vector<bool> CurrentStatus;
};