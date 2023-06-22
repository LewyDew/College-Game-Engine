#include "ResourceManager.h"

ResourceManager::ResourceManager()
	: TextureMap()
{
	// Nothing here...
}

ResourceManager::~ResourceManager()
{
	// Delete all textures loaded in
	std::map< std::string, sf::Texture *>::iterator iter = 
										TextureMap.begin();

	for (; iter != TextureMap.end(); ++iter)
	{
		delete (*iter).second;
	}
}

bool ResourceManager::LoadTexture(const std::string & ResourceName, 
	                              const std::string & FileName )
{
	// Check if resource name is already taken...
	std::map< std::string, sf::Texture *>::iterator iter =
							TextureMap.find(ResourceName);

	// Don't do anything if it is
	if (iter != TextureMap.end())
	{
		return false;
	}
	
	// Try to load texture...
	sf::Texture * texture = new sf::Texture();
	bool IsGood = texture->loadFromFile(FileName);

	// Put it in map if successful
	if( IsGood == true )
	{
		TextureMap[ResourceName] = texture;
	}
	else
	{
		// Delete if not to prevent a memory leak...
		delete texture;
	}

	// Return validity to calling function
	return IsGood;
}

sf::Texture * ResourceManager::GetTexture(const std::string & ResourceName)
{
	std::map< std::string, sf::Texture *>::iterator iter = 
						TextureMap.find( ResourceName );

	if (iter == TextureMap.end())
	{
		return nullptr;
	}

	return (*iter).second;
}
