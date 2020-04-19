#include "win.h"

#include "Objects/common_things.h"
#include "Sprites/sprites.h"

namespace LudumDare{

	static float timer=0;
	static const float maxTimer=5.0f;
	static int actualSprite=0;
	static const int maxSprites=9;
	static Texture2D asd;
	Win::Win(){
		for(int i=0;i<maxSprites;i++)
			_winSprites[i]=winSprites[i];
		timer=0;
		actualSprite=0;
		asd=onTutorialButtonsSprite;
	}
	Win::~Win(){

	}
	void Win::run(){
		update();
		draw();
	}
	void Win::update(){
		timer+=GetFrameTime();
		if(timer>=maxTimer){
			timer=0;
			actualSprite++;
			if(actualSprite>=maxSprites)
				gameState=onMenu;
		}
	}
	void Win::draw(){
		DrawTexture(_winSprites[actualSprite],0,0,WHITE);
	}


}