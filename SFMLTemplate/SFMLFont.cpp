#include "ResourceManager.h"
#include "SFMLFont.h"
#include "SFMLGame.h"
#include "SFMLGameObject.h"
#include "SFMLMouse.h"
#include "SFMLRoom.h"
SFMLFont::SFMLFont(const std::string & ResourceName)
	: SFMLGameObject( ResourceName, 0, 0, 16, 16)
{
	// Nothing here...
}

void SFMLFont::Draw()
{
	
}


void SFMLFont::Update( const sf::Time & DeltaTime)
{
	
}

void SFMLFont::DrawString(float X, float Y, const std::string & Text, const sf::Color & Color)
{
	SetPosition(X, Y);
	SetImageTint(Color);
	SetImageAlpha(255);
	for (char c : Text)
	{
		SetImageIndex(c);
		SFMLGameObject::Draw();
		SetX(GetX() + ( GetImageScaleX() *  GetSpriteWidth()));
	}
}