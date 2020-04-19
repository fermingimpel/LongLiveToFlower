#include "win.h"

#include "Objects/common_things.h"
#include "Sprites/sprites.h"

namespace LudumDare{

	static float timer=0;
	static const float maxTimer=3.0f;
	static int actualSprite=0;
	static const int maxSprites=9;

	Win::Win(){
		for(int i=0;i<maxSprites;i++)
			_winSprites[i]=winSprites[i];
		timer=0;
		actualSprite=0;
	}
	Win::~Win(){

	}
	void Win::run(){
		update();
	}
	void Win::update(){
		DrawTexture(_winSprites[actualSprite],0,0,WHITE);

		timer+=GetFrameTime();
		if(timer>=maxTimer){
			timer=0;
			actualSprite++;
			if(actualSprite>=maxSprites)
				gameState=onMenu;
		}
	}


}