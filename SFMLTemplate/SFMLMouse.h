#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class SFMLMouse
{
public:
	enum Buttons
	{
		LEFT = 0,
		MIDDLE,
		RIGHT,
		X1,
		X2
	};
	
	static SFMLMouse * GetInstance();

	void Update();

	bool IsButtonPressed(Buttons Button);
	bool IsButtonDown(Buttons Button);
	bool IsButtonReleased(Buttons Button);
	bool IsButtonUp(Buttons Button);

	sf::Vector2i GetPosition();
	void SetPosition(const sf::Vector2i & Value);
	void SetPosition(int X, int Y);
	void SetPositionX(int Value);
	void SetPositionY(int Value);

private:
	SFMLMouse();

	static SFMLMouse * Instance;

	std::vector<bool> PreviousStatus;
	std::vector<bool> CurrentStatus;
};