#pragma once
#include "TextureLoader.h"


/****************************************************
 * 
 *  
 * 
 *
 ****************************************************/

class PNG_Loader : public TextureLoader
{
	public:

		PNG_Loader();

		std::string getLoaderType() const;

		virtual void loadNewTexture() override;

		virtual void bindNewTexture(int tempTexture) override;

		virtual void unbindOldTexture() override;

};
