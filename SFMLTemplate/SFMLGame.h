#ifndef SFMLGAME_H
#define SFMLGAME_H

#include <SFML/Graphics.hpp>

class SFMLRoom;
class ResourceManager;

// ------------------
// Use as a singleton
// ------------------
class SFMLGame
{
public: // Functions

	// Destructor
	virtual ~SFMLGame();

	// Get singleton instance
	static SFMLGame * GetInstance();

	// Run the main game loop
	virtual void Run( SFMLRoom * StartingRoom );

	// Handle OS messages
	virtual void MessageHandling();

	// Update the game
	virtual void Update(const sf::Time & DeltaTime);

	// Draw the game
	virtual void Draw();

	// Get the render window
	sf::RenderWindow * GetWindow();

	// Reset the render window
	void ResetWindow();

	// Change the current room
	void ChangeRoom(SFMLRoom * NewNextRoom);

	// Get the current room
	SFMLRoom * GetCurrentRoom();

	// Get title bar text
	std::string GetTitleBar();

	// Set title bar text
	void SetTitleBar(const std::string & TitleBarText, bool CallResetWindowFunction = false);

	// Get window width
	unsigned int GetWindowWidth();

	// Set window width
	void SetWindowWidth(unsigned int Width, bool CallResetWindowFunction = false);

	// Get window height
	unsigned int GetWindowHeight();

	// Set window height
	void SetWindowHeight(unsigned int Height, bool CallResetWindowFunction = false);
		
	// Get FPS
	unsigned int GetFPS();

	// Set FPS
	void SetFPS(unsigned int FPS);
	
	// Get background color
	sf::Color GetBackgroundColor();

	// Set background color
	void SetBackgroundColor(const sf::Color & NewColor);

	ResourceManager * GetResourceManager();

	void ActuallyChangeRoom();

private:
	// Maintain the background drawing color
	sf::Color BackgroundColor;

	// Constructor
	SFMLGame();

	// Singleton instance
	static SFMLGame * Instance;

	// Render window
	sf::RenderWindow * Window;

	// the current room in play
	SFMLRoom * CurrentRoom;

	// Maintain how long to wait between game frames
	sf::Time FrameDelay;

	ResourceManager * Manager;

	// Width of the render window
	static unsigned int WindowWidth;

	// Height of the render window
	static unsigned int WindowHeight;

	// Is the game in fixed or variable time mode
	static bool IsFixedTimeStep;

	// How many frames per second are we trying to run at
	static unsigned int FPS;

	// Is the game running fullscreen
	static bool IsFullscreen;

	// Title bar for the render window
	static std::string TitleBar;

	SFMLRoom * NextRoom;
};

#endif