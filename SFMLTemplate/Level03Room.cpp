
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
#include "Solid.h"
#include "SFMLBox.h"
#include "goal.h"
#include "Player.h"
#include "GoalChecker.h"
#include <fstream>
#include <iostream>
#include <sstream>
Level03Room::Level03Room()
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
	SFMLWall * Wall1 = InstanceCreate(new SFMLWall("Wall", 60, 60));
	Wall1->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall2 = InstanceCreate(new SFMLWall("Wall", 120, 60));
	Wall2->SetSpriteOffset(sf::Vector2f(30, 30));
	
	SFMLWall * Wall3 = InstanceCreate(new SFMLWall("Wall", 180, 60));
	Wall3->SetSpriteOffset(sf::Vector2f(30, 30));
	
	SFMLWall * Wall4 = InstanceCreate(new SFMLWall("Wall", 240, 60));
	Wall4->SetSpriteOffset(sf::Vector2f(30, 30));
	
	SFMLWall * Wall5 = InstanceCreate(new SFMLWall("Wall", 300, 60));
	Wall5->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall6 = InstanceCreate(new SFMLWall("Wall", 60, 120));
	Wall6->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall7 = InstanceCreate(new SFMLWall("Wall", 300, 120));
	Wall7->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall8 = InstanceCreate(new SFMLWall("Wall", 60, 180));
	Wall8->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall9 = InstanceCreate(new SFMLWall("Wall", 300, 180));
	Wall9->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall10 = InstanceCreate(new SFMLWall("Wall", 60, 240));
	Wall10->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall11 = InstanceCreate(new SFMLWall("Wall", 300, 240));
	Wall11->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall12 = InstanceCreate(new SFMLWall("Wall", 60, 300));
	Wall12->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall13 = InstanceCreate(new SFMLWall("Wall", 120, 300));
	Wall13->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall14 = InstanceCreate(new SFMLWall("Wall", 180, 300));
	Wall14->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall15 = InstanceCreate(new SFMLWall("Wall", 300, 300));
	Wall15->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall16 = InstanceCreate(new SFMLWall("Wall", 360, 300));
	Wall16->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall17 = InstanceCreate(new SFMLWall("Wall", 420, 300));
	Wall17->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall18 = InstanceCreate(new SFMLWall("Wall", 540, 300));
	Wall18->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall19 = InstanceCreate(new SFMLWall("Wall", 420, 240));
	Wall19->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall20 = InstanceCreate(new SFMLWall("Wall", 420, 180));
	Wall20->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall24 = InstanceCreate(new SFMLWall("Wall", 360, 420));
	Wall24->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall21 = InstanceCreate(new SFMLWall("Wall", 540, 240));
	Wall21->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall22 = InstanceCreate(new SFMLWall("Wall", 540, 180));
	Wall22->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall23= InstanceCreate(new SFMLWall("Wall", 480, 180));
	Wall23->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall25 = InstanceCreate(new SFMLWall("Wall", 540, 240));
	Wall25->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall26 = InstanceCreate(new SFMLWall("Wall", 120, 360));
	Wall26->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall27 = InstanceCreate(new SFMLWall("Wall", 180, 360));
	Wall27->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall28 = InstanceCreate(new SFMLWall("Wall", 120, 420));
	Wall28->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall29 = InstanceCreate(new SFMLWall("Wall", 120, 480));
	Wall29->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall30 = InstanceCreate(new SFMLWall("Wall", 120, 540));
	Wall30->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall31 = InstanceCreate(new SFMLWall("Wall", 180, 540));
	Wall31->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall32 = InstanceCreate(new SFMLWall("Wall", 240, 540));
	Wall32->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall33 = InstanceCreate(new SFMLWall("Wall", 300, 540));
	Wall33->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall34 = InstanceCreate(new SFMLWall("Wall", 360, 540));
	Wall34->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall35 = InstanceCreate(new SFMLWall("Wall", 360, 480));
	Wall35->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall36 = InstanceCreate(new SFMLWall("Wall", 420, 480));
	Wall36->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall37 = InstanceCreate(new SFMLWall("Wall", 480, 480));
	Wall37->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall38= InstanceCreate(new SFMLWall("Wall", 540, 480));
	Wall38->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall39 = InstanceCreate(new SFMLWall("Wall", 540, 420));
	Wall39->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLWall * Wall40 = InstanceCreate(new SFMLWall("Wall", 540, 360));
	Wall40->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLBox * Box1 = InstanceCreate(new SFMLBox("Box", 180, 180));
	Box1->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLBox * Box2 = InstanceCreate(new SFMLBox("Box", 180, 240));
	Box2->SetSpriteOffset(sf::Vector2f(30, 30));

	SFMLBox * Box3 = InstanceCreate(new SFMLBox("Box", 240, 180));
	Box3->SetSpriteOffset(sf::Vector2f(30, 30));

	goal * Goal1 = InstanceCreate(new goal("Goal", 480, 240));
	Goal1->SetSpriteOffset(sf::Vector2f(30, 30));
	goal * Goal2 = InstanceCreate(new goal("Goal", 480, 300));
	Goal2->SetSpriteOffset(sf::Vector2f(30, 30));
	goal * Goal3 = InstanceCreate(new goal("Goal", 480, 360));
	Goal3->SetSpriteOffset(sf::Vector2f(30, 30));
	Player * Guy = InstanceCreate(new Player("Guy", 120, 120, 2, 1));
	Guy->SetSpriteOffset(sf::Vector2f(30,30));
	Guy->SetImageSpeed(0);
	GoalChecker * checker = InstanceCreate(new GoalChecker("Wall", -10000, 10000, 1, 1, 3));

}
