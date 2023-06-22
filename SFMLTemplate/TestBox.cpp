#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

#include "SFMLFont.h"
#include "SFMLMouse.h"
#include "TestBox.h"

int score = 0;

TestBox::TestBox(float X, float Y)
	: SFMLGameObject( "TestBox", X, Y )
{
	// Nothing here...
}

void TestBox::Update(const sf::Time & DeltaTime)
{
	sf::Vector2i Pos = SFMLMouse::GetInstance()->GetPosition();
	SetX(Pos.x);
	SetY(Pos.y);
	SFMLGameObject::Update(DeltaTime);
}

void TestBox::Draw()
{
	SFMLGameObject::Draw();
}

void TestBox::OnCollision(SFMLGameObject * Object)
{
	++score;
}