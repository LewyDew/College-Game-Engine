
#include "Level01Room.h"
#include "Level02Room.h"
#include "Level03Room.h"
#include "MainMenuRoom.h"
#include "ResourceManager.h"
#include "SFMLButton.h"
#include "SFMLGame.h"
#include "SFMLFont.h"
#include "TestBox.h"
#include "SFMLWall.h"
#include "SFMLBox.h"
#include "goal.h"
#include "Player.h"
#include "GoalChecker.h"
Level02Room::Level02Room()
{
	// ---------------
	// Sprite includes
	// ---------------
	SFMLGame::GetInstance()->GetResourceManager()->LoadTexture("MainMenuBackground", "MainMenu_back.png");
	SFMLGame::GetInstance()->GetResourceManager()->LoadTexture("Wall", "wall_spr.png");
	SFMLGame::GetInstance()->GetResourceManager()->LoadTexture("Box", "box_spr.png");
	SFMLGame::GetInstance()->GetResourceManager()->LoadTexture("Goal", "goal_spr.png");
	SFMLGame::GetInstance()->GetResourceManager()->LoadTexture("Guy", "guy_spr_strip2.png");


	// ---------------
	// Object includes
	// ---------------

	// NOTICE THE NEW WAY TO CREATE AN OBJECT
	// Do things this way to avoid crazy crashes
	
	SFMLGameObject * init = InstanceCreate(new SFMLGameObject("MainMenuBackground", 0, 0));
	init->SetImageScaleX(4);
	init->SetImageScaleY(4);
	init->SetDepth(-10);
	SFMLWall * Wall1 = InstanceCreate(new SFMLWall("Wall", 180, 60));
	Wall1->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall2 = InstanceCreate(new SFMLWall("Wall", 240, 60));
	Wall2->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall3 = InstanceCreate(new SFMLWall("Wall", 300, 60));
	Wall3->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall4 = InstanceCreate(new SFMLWall("Wall", 180, 120));
	Wall4->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall5 = InstanceCreate(new SFMLWall("Wall", 300, 120));
	Wall5->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall6 = InstanceCreate(new SFMLWall("Wall", 360, 120));
	Wall6->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall7 = InstanceCreate(new SFMLWall("Wall", 420, 120));
	Wall7->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall8 = InstanceCreate(new SFMLWall("Wall", 480, 120));
	Wall8->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall9 = InstanceCreate(new SFMLWall("Wall", 480, 180));
	Wall9->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall10 = InstanceCreate(new SFMLWall("Wall", 480, 240));
	Wall10->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall11 = InstanceCreate(new SFMLWall("Wall", 420, 240));
	Wall11->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall12 = InstanceCreate(new SFMLWall("Wall", 420, 300));
	Wall12->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall13 = InstanceCreate(new SFMLWall("Wall", 360, 300));
	Wall13->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall14 = InstanceCreate(new SFMLWall("Wall", 360, 360));
	Wall14->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall15 = InstanceCreate(new SFMLWall("Wall", 360, 420));
	Wall15->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall16 = InstanceCreate(new SFMLWall("Wall", 300, 420));
	Wall16->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall17 = InstanceCreate(new SFMLWall("Wall", 240, 420));
	Wall17->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall18 = InstanceCreate(new SFMLWall("Wall", 240, 360));
	Wall18->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall19 = InstanceCreate(new SFMLWall("Wall", 240, 300));
	Wall19->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall20 = InstanceCreate(new SFMLWall("Wall", 180, 300));
	Wall20->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall24 = InstanceCreate(new SFMLWall("Wall", 120, 300));
	Wall24->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall21 = InstanceCreate(new SFMLWall("Wall", 60, 300));
	Wall21->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall22 = InstanceCreate(new SFMLWall("Wall", 60, 240));
	Wall22->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall23 = InstanceCreate(new SFMLWall("Wall", 60, 180));
	Wall23->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall25 = InstanceCreate(new SFMLWall("Wall", 120, 180));
	Wall25->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall26 = InstanceCreate(new SFMLWall("Wall", 180, 120));
	Wall26->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall27 = InstanceCreate(new SFMLWall("Wall", 180, 180));
	Wall27->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLBox * Box1 = InstanceCreate(new SFMLBox("Box", 300, 240));
	Box1->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLBox * Box2 = InstanceCreate(new SFMLBox("Box", 240, 240));
	Box2->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLBox * Box3 = InstanceCreate(new SFMLBox("Box", 240, 180));
	Box3->SetSpriteOffset(sf::Vector2f(30, 30));

	goal * Goal1 = InstanceCreate(new goal("Goal", 120, 240));
	Goal1->SetSpriteOffset(sf::Vector2f(30, 30));
	goal * Goal2 = InstanceCreate(new goal("Goal", 240, 120));
	Goal2->SetSpriteOffset(sf::Vector2f(30, 30));
	goal * Goal3 = InstanceCreate(new goal("Goal", 420, 180));
	Goal3->SetSpriteOffset(sf::Vector2f(30, 30));
	Player * Guy = InstanceCreate(new Player("Guy", 300, 360, 2, 1));
	Guy->SetSpriteOffset(sf::Vector2f(30, 30));
	Guy->SetImageSpeed(0);
	GoalChecker * checker = InstanceCreate(new GoalChecker("Wall", -10000, 10000, 1, 1, 2));

}





