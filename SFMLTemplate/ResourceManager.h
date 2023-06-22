#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class ResourceManager
{
public:
	ResourceManager();

	~ResourceManager();

	bool LoadTexture(const std::string & ResourceName,
		             const std::string & FileName);

	sf::Texture * GetTexture(const std::string & ResourceName);
		                     

private:
	std::map< std::string, sf::Texture *> TextureMap;
};
