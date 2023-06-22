// Include files
#include "stdafx.h"
#include <cassert>
#include <iostream>
#include "ResourceManager.h"
#include "SFMLGame.h"
#include "SFMLKeyboard.h"
#include "SFMLMouse.h"
#include "SFMLRoom.h"

// STATIC - Instance pointer for singleton design pattern
SFMLGame * SFMLGame::Instance(nullptr);

// STATIC - Is fixed time step?  Or is it non-fixed?
// Default true to mimic GameMaker
// Set to false to mimic Unity/Unreal et al
bool SFMLGame::IsFixedTimeStep(true);

// STATIC - The game window width
// NOTE:  ResetWindow() must be called if this variable is changed
unsigned int SFMLGame::WindowWidth(1280);

// STATIC - The game window height
// NOTE:  ResetWindow() must be called if this variable is changed
unsigned int SFMLGame::WindowHeight(720);

// STATIC - The game window title bar
// NOTE:  ResetWindow() must be called if this variable is changed
std::string  SFMLGame::TitleBar("");

// STATIC - The fullscreen status of the window
// NOTE:  ResetWindow() must be called if this variable is changed
bool SFMLGame::IsFullscreen(false);

// STATIC - The desired game frame rate
unsigned int SFMLGame::FPS(60);

// -----------
// Constructor
// -----------
SFMLGame::SFMLGame()
	: BackgroundColor(sf::Color::Black),
	Window(new sf::RenderWindow()),
	CurrentRoom(nullptr),
	FrameDelay(),
	Manager(new ResourceManager()),
	NextRoom(nullptr)
{
	// Use static variables listed above to start and open the window
	ResetWindow();
}

// ----------
// Destructor
// ----------
SFMLGame::~SFMLGame()
{
	// Delete all relevant pointers
	delete Window;
	delete Instance;
	delete Manager;
}

// -------------------------------------------
// Get the singleton pointer to the game class
// -------------------------------------------
SFMLGame * SFMLGame::GetInstance()
{
	// New up a game class if this is the first time the function is called
	if (Instance == nullptr)
	{
		Instance = new SFMLGame();
	}

	// Return the pointer
	return Instance;
}

// ---------------------------
// Get the game window pointer
// ---------------------------
sf::RenderWindow * SFMLGame::GetWindow()
{
	return Window;
}

// --------------------------------------------------
// Change the current game room - Game Programer Call
// --------------------------------------------------
void SFMLGame::ChangeRoom(SFMLRoom * NewNextRoom)
{
	// NO memory leak if you spam this function
	// Whatever is the last call to this function 
	// will be the next room to be loaded and run

	// Delete what came before it...?
	if (NextRoom != nullptr)
	{
		delete NextRoom;
	}

	// Then set it up to be the current room
	NextRoom = NewNextRoom;
}

// ----------------------------------------------------
// Change the current game room - Engine Programer Call
// ----------------------------------------------------
void SFMLGame::ActuallyChangeRoom()
{
	// Delete what came before it...
	if (NextRoom != nullptr)
	{
		// The room is dead!
		delete CurrentRoom;
		// Long live the room!
		CurrentRoom = NextRoom;
	}

	// Reset for next trip through the loop
	NextRoom = nullptr;
}

// ----------------------------
// Get the current game room
// ----------------------------
SFMLRoom * SFMLGame::GetCurrentRoom()
{
	return CurrentRoom;
}

// -----------------------------------------------------------
// Reset the game window
// Must call this if any of the window variables are modified,
// or else one migth not see the changes actually occur
// -----------------------------------------------------------
void SFMLGame::ResetWindow()
{
	// Style sets up the fullscreen status
	int Style(sf::Style::Default);
	Style ^= (IsFullscreen) ? sf::Style::Fullscreen : sf::Style::None;
	
	// Call this function to do the work
	// It says it will close the window already created and start fresh
	Window->create(sf::VideoMode(WindowWidth, WindowHeight), TitleBar, Style);

	// Set up new framerate
	SetFPS(FPS);
}

ResourceManager * SFMLGame::GetResourceManager()
{
	return Manager;
}

// -------
// Get FPS
// -------
unsigned int SFMLGame::GetFPS()
{
	return FPS;
}

// -------
// Set FPS
// -------
void SFMLGame::SetFPS(unsigned int FPS)
{
	// Set up new framerate...  
	// Number of milliseconds per frame is this calculation below
	FrameDelay = sf::microseconds(1000000 / FPS);
}

// --------------------
// Get background color
// --------------------
sf::Color SFMLGame::GetBackgroundColor()
{
	return BackgroundColor;
}

// --------------------
// Set background color
// --------------------
void SFMLGame::SetBackgroundColor(const sf::Color & NewColor)
{
	BackgroundColor = NewColor;
}

// --------------------------------------
// Handle any OS messages as they come in
// --------------------------------------
void SFMLGame::MessageHandling()
{
	sf::Event Event;
	while (Window->pollEvent(Event))
	{
		// Handle someone clicking to close the window
		// Obviously only works when NOT in fullscreen mode
		if (Event.type == sf::Event::Closed)
		{
			Window->close();
		}
	}
}

// ------------------
// The main game loop
// ------------------
void SFMLGame::Run( SFMLRoom * StartingRoom )
{
	// Avoid memory leaks
	if (CurrentRoom != nullptr)
	{
		delete CurrentRoom;
	}

	// Set the current room
	CurrentRoom = StartingRoom;
	
	// set up timers
	sf::Clock Clock;
	sf::Time TimeSinceLastUpdate = sf::Time::Zero;

	// Pretty much run indefinitely
	while (Window->isOpen() && (CurrentRoom->ShouldQuitGame() == false))
	{
		// Handle messaging
		MessageHandling();

		// Get the amount of time since the last update
		sf::Time DeltaTime = Clock.restart();

		// Handle the timing differently based on preference
		if (IsFixedTimeStep)
		{
			// Update time since last update call
			TimeSinceLastUpdate += DeltaTime;
			// Call update only if enough time has transpired 
			if (TimeSinceLastUpdate.asMicroseconds() > FrameDelay.asMicroseconds())
			{
				// Input handlers
				SFMLKeyboard::GetInstance()->Update();
				SFMLMouse::GetInstance()->Update();
				// Do actual update
				Update(TimeSinceLastUpdate);
				// Don't make it zero since it could be a few frames behind
				TimeSinceLastUpdate -= FrameDelay;
			}
		}
		else
		{
			// Input handlers
			SFMLKeyboard::GetInstance()->Update();
			SFMLMouse::GetInstance()->Update();
			// Update as often and as fast as you can
			Update(DeltaTime);
		}

		// Always keep drawing no matter what
		Draw();
		ActuallyChangeRoom();
	}
}

void SFMLGame::Update(const sf::Time & DeltaTime)
{
	// Remove this when you feel comfortable that it all works
	// This is slowing down the game!
	std::cout << "Time between frames: " << DeltaTime.asMicroseconds() << " microseconds\n";

	// Update the game room
	assert( CurrentRoom != nullptr );
	CurrentRoom->Update(DeltaTime);
}

void SFMLGame::Draw()
{
	// Clear the current window
	assert( Window != nullptr );
	Window->clear( BackgroundColor );

	// Draw the current room
	assert( CurrentRoom != nullptr );
	CurrentRoom->Draw();

	// Display the window
	Window->display();
}

// Get title bar text
std::string SFMLGame::GetTitleBar()
{
	return TitleBar;
}

// Set title bar text
void SFMLGame::SetTitleBar(const std::string & TitleBarText, bool CallResetWindowFunction)
{
	TitleBar = TitleBarText;
	Window->setTitle(TitleBar);

	if (CallResetWindowFunction == true)
	{
		ResetWindow();
	}
}

// Get window width
unsigned int SFMLGame::GetWindowWidth()
{
	return WindowWidth;
}

// Set window width
void SFMLGame::SetWindowWidth(unsigned int Width, bool CallResetWindowFunction)
{
	WindowWidth = Width;
	Window->setSize(sf::Vector2u(WindowWidth, WindowHeight));

	if (CallResetWindowFunction == true)
	{
		ResetWindow();
	}
}

// Get window height
unsigned int SFMLGame::GetWindowHeight()
{
	return WindowHeight;
}

// Set window width
void SFMLGame::SetWindowHeight(unsigned int Height, bool CallResetWindowFunction)
{
	WindowHeight = Height;
	Window->setSize(sf::Vector2u(WindowWidth, WindowHeight));

	if (CallResetWindowFunction == true)
	{
		ResetWindow();
	}
}

