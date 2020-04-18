#include "sprites.h"

namespace LudumDare{

	//Gameplay
	Texture2D plantsSprites[7];
	Texture2D sunSprite;
	Texture2D skySprite;
	Texture2D waterCanSprite;
	Texture2D windowSprite;

	//Menu
	Texture2D menuSprite;
	Texture2D playButtonSprite;
	Texture2D creditsButtonSprite;
	Texture2D exitButtonSprite;

	void loadSprites(){
		//Gameplay
		plantsSprites[0]=LoadTexture("res/Assets/Sprites/Plant1.png");
		plantsSprites[1]=LoadTexture("res/Assets/Sprites/Plant2.png");
		plantsSprites[2]=LoadTexture("res/Assets/Sprites/Plant3.png");
		plantsSprites[3]=LoadTexture("res/Assets/Sprites/Plant4.png");
		plantsSprites[4]=LoadTexture("res/Assets/Sprites/Plant5.png");
		plantsSprites[5]=LoadTexture("res/Assets/Sprites/Plant6.png");
		plantsSprites[6]=LoadTexture("res/Assets/Sprites/Plant7.png");
		sunSprite=LoadTexture("res/Assets/Sprites/Sun.png");
		skySprite=LoadTexture("res/Assets/Sprites/Sky.png");
		waterCanSprite=LoadTexture("res/Assets/Sprites/WaterCan.png");
		windowSprite=LoadTexture("res/Assets/Sprites/Window.png");

		//Menu
		menuSprite=LoadTexture("res/Assets/Sprites/MenuSprite.png");
		playButtonSprite=LoadTexture("res/Assets/Sprites/PlayButton.png");
		creditsButtonSprite=LoadTexture("res/Assets/Sprites/CreditsButton.png");
		exitButtonSprite=LoadTexture("res/Assets/Sprites/ExitButton.png");
	}
	void unloadSprites(){
		//Unload Gameplay sprites
		for(int i=0;i<7;i++)
			UnloadTexture(plantsSprites[i]);
		UnloadTexture(sunSprite);
		UnloadTexture(skySprite);
		UnloadTexture(waterCanSprite);
		UnloadTexture(windowSprite);

		//Unload Menu Sprites
		UnloadTexture(menuSprite);
		UnloadTexture(playButtonSprite);
		UnloadTexture(creditsButtonSprite);
		UnloadTexture(exitButtonSprite);
	}

}