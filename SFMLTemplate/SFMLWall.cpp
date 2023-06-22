#include "ResourceManager.h"
#include "SFMLFont.h"
#include "SFMLGame.h"
#include "SFMLGameObject.h"
#include "SFMLMouse.h"
#include "SFMLRoom.h"
#include "Solid.h"
#include "SFMLWall.h"
SFMLWall::SFMLWall(const std::string & ResourceName,
	float XStart,
	float YStart,
	int HFrames,
	int VFrames):
	Solid(ResourceName,
		XStart,
		YStart,
		HFrames,
		VFrames)
{
	
}