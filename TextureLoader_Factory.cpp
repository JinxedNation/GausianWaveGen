#include "TextureLoader_Factory.h"


std::unique_ptr<TextureLoader> TextureLoader_Factory::generateTexture(std::string textureFile)
{
	std::string fileType = textureFile.substr(textureFile.find_last_of(".") + 1);


	if (fileType == "jpg" || fileType == "jpeg")
	{
		return std::make_unique<JPG_Loader>(textureFile);

	}
	else if (fileType == "png")
	{
		return std::make_unique<PNG_Loader>(textureFile);
	}
}