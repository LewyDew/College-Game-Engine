#include "Level01Room.h"
#include "Level02Room.h"
#include "Level03Room.h"
#include "MainMenuRoom.h"
#include "ResourceManager.h"
#include "SFMLButton.h"
#include "SFMLGame.h"
#include "SFMLFont.h"
#include "TestBox.h"

void GoToLevel01(SFMLGameObject * Object)
{
	SFMLGame::GetInstance()->ChangeRoom(new Level01Room());
}

void GoToLevel02(SFMLGameObject * Object)
{
	SFMLGame::GetInstance()->ChangeRoom(new Level02Room());
}

void GoToLevel03(SFMLGameObject * Object)
{
	SFMLGame::GetInstance()->ChangeRoom(new Level03Room());
}

void QuitGame(SFMLGameObject * Object)
{
	SFMLGame::GetInstance()->GetCurrentRoom()->QuitGameImmediately();
}

MainMenuRoom::MainMenuRoom()
{
	// ---------------
	// Sprite includes
	// ---------------
	SFMLGame::GetInstance()->GetResourceManager()->LoadTexture("MainMenuBackground",   "MainMenu_back.png");
	SFMLGame::GetInstance()->GetResourceManager()->LoadTexture("QuitGameButtonSprite", "QuitGameButtonSprite.png");
	SFMLGame::GetInstance()->GetResourceManager()->LoadTexture("Level01ButtonSprite",  "Level01ButtonSprite.png");
	SFMLGame::GetInstance()->GetResourceManager()->LoadTexture("Level02ButtonSprite",  "Level02ButtonSprite.png");
	SFMLGame::GetInstance()->GetResourceManager()->LoadTexture("Level03ButtonSprite",  "Level03ButtonSprite.png");
	SFMLGame::GetInstance()->GetResourceManager()->LoadTexture("Font", "ASCIIFont.png");
	// ---------------
	// Object includes
	// ---------------

	// NOTICE THE NEW WAY TO CREATE AN OBJECT
	// Do things this way to avoid crazy crashes
	SFMLGameObject * init = InstanceCreate(new SFMLGameObject("MainMenuBackground", 0, 0));
	init->SetImageScaleX(4);
	init->SetImageScaleY(4);
	init->SetDepth(-10);










	SFMLFont * Font1 = InstanceCreate(new SFMLFont("Font"));
	Font1->DrawString(390, 120, "High Score: ", sf::Color(255,255,255,1));
	SFMLGameObject * Level1Button = InstanceCreate( new SFMLButton( "Level01ButtonSprite", sf::Vector2f(390, 120), GoToLevel01));
	SFMLFont * Font2 = InstanceCreate(new SFMLFont("Font"));
	Font2->DrawString(390, 260, "High Score: ", sf::Color(255, 255, 255, 1));
	SFMLGameObject * Level2Button = InstanceCreate( new SFMLButton( "Level02ButtonSprite", sf::Vector2f(390, 260), GoToLevel02));
	SFMLFont * Font3 = InstanceCreate(new SFMLFont("Font"));
	Font3->DrawString(390, 400, "High Score: ", sf::Color(255, 255, 255, 1));
	SFMLGameObject * Level3Button = InstanceCreate( new SFMLButton( "Level03ButtonSprite", sf::Vector2f(390, 400), GoToLevel03));
	SFMLGameObject * QuitButton = InstanceCreate(new SFMLButton("QuitGameButtonSprite", sf::Vector2f(390, 560), QuitGame));


	//InstanceCreate( new SFMLButton( "QuitGameButtonSprite", sf::Vector2f(100, 100), QuitGame));

}
