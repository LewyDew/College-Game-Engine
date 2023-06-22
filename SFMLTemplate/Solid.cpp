#include "ResourceManager.h"
#include "SFMLFont.h"
#include "SFMLGame.h"
#include "SFMLGameObject.h"
#include "SFMLMouse.h"
#include "SFMLRoom.h"
#include "Solid.h"
#include "SFMLBox.h"
Solid::Solid(const std::string & ResourceName,
	float XStart,
	float YStart,
	int HFrames,
	int VFrames)
	:SFMLGameObject( ResourceName,
		XStart,
		YStart,
		HFrames,
		VFrames)	
{

}
