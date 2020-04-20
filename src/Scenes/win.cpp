#include "win.h"

#include "Objects/common_things.h"
#include "Sprites/sprites.h"

namespace LudumDare{

	static float timer=0;
	static const float maxTimer=5.0f;
	static int actualSprite=0;
	static const int maxSprites=9;
	static float soundTimer=0;
	static const float maxSoundTimer=1.5f;
	static bool soundPlayed=false;
	Win::Win(){
		for(int i=0;i<maxSprites;i++)
			_winSprites[i]=winSprites[i];
		timer=0;
		actualSprite=0;
		soundTimer=0;
		soundPlayed=false;
		_winSound=winSound;
		SetSoundVolume(_winSound,0.2f);
	}
	Win::~Win(){

	}
	void Win::run(){
		update();
		draw();
	}
	void Win::update(){
		if(soundPlayed==false){
			soundTimer+=GetFrameTime();
			if(soundTimer>=maxSoundTimer){
				soundTimer=0;
				PlaySound(_winSound);
				soundPlayed=true;
			}
		}
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