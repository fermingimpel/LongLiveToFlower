#ifndef SPRITES_H
#define SPRITES_H

#include "raylib.h"

namespace LudumDare{

	//Gameplay
	extern Texture2D plantsSprites[7];
	extern Texture2D sunSprite;
	extern Texture2D skySprite;
	extern Texture2D waterCanSprite;
	extern Texture2D windowSprite;

	//Menu
	extern Texture2D menuSprite;
	extern Texture2D playButtonSprite;
	extern Texture2D creditsButtonSprite;
	extern Texture2D exitButtonSprite;



	//Load & Unload
	void loadSprites();
	void unloadSprites();

}

#endif