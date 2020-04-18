#include "sprites.h"

namespace LudumDare{

	//Gameplay
	Texture2D windowSprite;
	Texture2D skySprite;
	Texture2D plantsSprites[7];
	Texture2D sunSprite;
	Texture2D waterSprite;
	Texture2D needWaterSprite;
	Texture2D needSunSprite;
	//Menu
	Texture2D menuSprite;
	Texture2D playButtonSprite;
	Texture2D tutorialButtonSprite;
	Texture2D exitButtonSprite;

	void loadSprites(){
		//Gameplay
		windowSprite=LoadTexture("res/Assets/Sprites/Window.png");
		skySprite=LoadTexture("res/Assets/Sprites/Sky.png");
		plantsSprites[0]=LoadTexture("res/Assets/Sprites/Plant1.png");
		plantsSprites[1]=LoadTexture("res/Assets/Sprites/Plant2.png");
		plantsSprites[2]=LoadTexture("res/Assets/Sprites/Plant3.png");
		plantsSprites[3]=LoadTexture("res/Assets/Sprites/Plant4.png");
		plantsSprites[4]=LoadTexture("res/Assets/Sprites/Plant5.png");
		plantsSprites[5]=LoadTexture("res/Assets/Sprites/Plant6.png");
		plantsSprites[6]=LoadTexture("res/Assets/Sprites/Plant7.png");
		sunSprite=LoadTexture("res/Assets/Sprites/Sun.png");
		waterSprite=LoadTexture("res/assets/Sprites/WaterCan.png");;
		needWaterSprite=LoadTexture("res/Assets/Sprites/NedWater.png");
		needSunSprite=LoadTexture("res/Assets/Sprites/NeedSun.png");

		//Menu
		menuSprite=LoadTexture("res/Assets/Sprites/MenuSprite.png");
		playButtonSprite=LoadTexture("res/Assets/Sprites/PlayButton.png");
		tutorialButtonSprite=LoadTexture("res/Assets/Sprites/CreditsButton.png");
		exitButtonSprite=LoadTexture("res/Assets/Sprites/ExitButton.png");
	}
	void unloadSprites(){
		//Unload Gameplay sprites
		for(int i=0;i<7;i++)
			UnloadTexture(plantsSprites[i]);
		UnloadTexture(windowSprite);
		UnloadTexture(skySprite);
		UnloadTexture(needWaterSprite);
		UnloadTexture(needSunSprite);

		//Unload Menu Sprites
		UnloadTexture(menuSprite);
		UnloadTexture(playButtonSprite);
		UnloadTexture(tutorialButtonSprite);
		UnloadTexture(exitButtonSprite);
	}

}