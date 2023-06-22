#include "ResourceManager.h"
#include "SFMLFont.h"
#include "SFMLGame.h"
#include "SFMLGameObject.h"
#include "SFMLMouse.h"
#include "SFMLRoom.h"
#include "Player.h"
#include "SFMLKeyboard.h"
#include "Solid.h"
#include "SFMLBox.h"
#include "goal.h"
#include "Player.h"
#include "GoalChecker.h"
#include "Level01Room.h"
#include "Level02Room.h"
#include "Level03Room.h"
#include "SFMLGame.h"
#include "MainMenuRoom.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>



GoalChecker::GoalChecker(const std::string & ResourceName,
	float XStart,
	float YStart,
	int HFrames,
	int VFrames,
	int lv)
	:SFMLGameObject(ResourceName,
		XStart,
		YStart,
		HFrames,
		VFrames)
{
	std::ifstream indata;
	level = lv;
	std::cout << "lv = " << lv << "\n";
	//attempting to get the player so I can check its score. When I do the next line it causes my program to crash
	//std::vector<Player*> players = SFMLGameObject::GetAllGameObjectsOfType<Player>();
	std::vector<Player*> players = SFMLGame::GetInstance()->GetCurrentRoom()->GetAllGameObjectsOfType<Player>();
	std::vector<Player*>::iterator It; // declare a general iterator
	/*if (players.empty())
		std::cout << "Vector players is empty\n";
	for (It = players.begin(); It != players.end(); ++It)
		std::cout << *It << '\t'; // output the current value that It is *pointing to
	*/
	std::cout << "got past vector\n";
	if (lv == 1)
		indata.open("level1.txt");
	if (lv == 2)
		indata.open("level2.txt");
	if (lv == 3)
		indata.open("level3.txt");
	//I attempted static cast here but it isn't working 
	//indata >> static_cast<std::string>(*players[1]->getScore());

	std::string line;
	// ifstream myfile("example.txt");
	if (indata.is_open())
	{
		std::cout << "File is open\n";
		while (getline(indata, line))
		{
			std::cout << line << '\n';
		}
		indata.close();
	}
	//else
	//{
		//std::cout << "Unable to open file";
	//}
	//system("PAUSE");
}


void GoalChecker::Update(const sf::Time & DeltaTime)
{
	std::ofstream data;
	std::string fn;		// file name

	std::vector<goal*> goals =  SFMLGameObject::GetAllGameObjectsOfType<goal>();
	int NumBoxWithGoal = 0;
	for (int i = 0; i < goals.size(); ++i)
	{
		if (goals[i]->HasBox())
			++NumBoxWithGoal;
	}

	std::vector<Player*> players = SFMLGame::GetInstance()->GetCurrentRoom()->GetAllGameObjectsOfType<Player>();
	std::vector<Player*>::iterator It; // declare a general iterator
	if (players.empty())
		std::cout << "Vector players is empty\n";
	for (It = players.begin(); It != players.end(); ++It)
		std::cout << *It << '\t'; // output the current value that It is *pointing to

	//std::string line;
	/*data.open(fn);

	if (data.is_open())
	{
		std::cout << "File is open\n";

			std::cout << line << '\n';
		data.close();
	}
	else
	{
		std::cout << "Unable to open file";
	}
	*/
	//system("PAUSE");

	if (NumBoxWithGoal == goals.size())
	{
		//Trying to write score to file by getting access to the player's score 
		//std::vector<Player*> player = SFMLGameObject::GetAllGameObjectsOfType<Player>();
	
		if (level == 1) {
			fn = "level1.txt";
			data.open(fn);
			data << std::to_string(players[0]->getScore());
		}
		if (level == 2) {
			fn = "level2.txt";
			data.open(fn);
			data << std::to_string(players[0]->getScore());
		}
		if (level == 3) {
			fn = "level3.txt";
			data.open(fn);
			data << std::to_string(players[0]->getScore());
		}
		SFMLGame::GetInstance()->ChangeRoom(new MainMenuRoom());
	}


	


	if(SFMLKeyboard::GetInstance()->IsKeyPressed(sf::Keyboard::Escape))
		SFMLGame::GetInstance()->ChangeRoom(new MainMenuRoom());
	
	//(new std::vector<goal> *goals->SFMLGameObject::GetAllGameObjectsOfType<goal>();
}

bool GoalChecker::HasBox()
{
	return (SFMLGameObject::PlaceMeeting<SFMLBox>(sf::Vector2f(this->GetPreviousPositionX(), this->GetPreviousPositionY())));
}
