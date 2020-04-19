#ifndef SPRITES_H
#define SPRITES_H

#include "raylib.h"

namespace LudumDare{

	//Gameplay
	extern Texture2D windowSprite;
	extern Texture2D skySprite;
	extern Texture2D plantsSprites[7];
	extern Texture2D plantDead;
	extern Texture2D sunSprite;
	extern Texture2D waterSprite;
	extern Texture2D needWaterSprite;
	extern Texture2D needSunSprite;

	//Menu
	extern Texture2D menuSprite;
	extern Texture2D playButtonSprite;
	extern Texture2D tutorialButtonSprite;
	extern Texture2D exitButtonSprite;
	extern Texture2D menuButtonSprite;
	extern Texture2D endButtonSprite;
	extern Texture2D loseTextSprite;
	extern Texture2D winSprites[9];

	//Load & Unload
	void loadSprites();
	void unloadSprites();

}

#endif