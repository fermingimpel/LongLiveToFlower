#include "lose.h"

#include "Sprites/sprites.h"
#include "Objects/common_things.h"

namespace LudumDare{

	static const float buttonsWidth=246;
	static const float buttonsHeight=53;
	static const float buttonsX=134;
	static const float playButtonY=173;
	static const float menuButtonY=238;
	static const float exitButtonY=304;

	static float soundTimer=0;
	static const float maxSoundTimer=1.5f;
	static bool soundPlayed;

	enum ButtonsEnd{
		nothing,
		play,
		menu,
		exit
	};
	static ButtonsEnd mouseInButton;
	static Vector2 mousePos;

	Lose::Lose(){
		_flower=new Flower();
		_flower->setDeatFlower();
		_windowSprite=windowSprite;
		_skySprite=skySprite;

		_endButtons=endButtonSprite;
		_playAgainButtonSprite=playButtonSprite;
		_menuButtonSprite=menuButtonSprite;
		_exitButtonSprite=exitButtonSprite;
		_loseText=loseTextSprite;
		
		_playAgainButtonRec.x=buttonsX;
		_playAgainButtonRec.y=playButtonY;
		_playAgainButtonRec.width=buttonsWidth;
		_playAgainButtonRec.height=buttonsHeight;

		_menuButtonRec.x=buttonsX;
		_menuButtonRec.y=menuButtonY;
		_menuButtonRec.width=buttonsWidth;
		_menuButtonRec.height=buttonsHeight;

		_exitButtonRec.x=buttonsX;
		_exitButtonRec.y=exitButtonY;
		_exitButtonRec.width=buttonsWidth;
		_exitButtonRec.height=buttonsHeight;

		mouseInButton=nothing;
		_loseSound=loseSound;
		SetSoundVolume(_loseSound,0.2f);
		soundPlayed=false;
		soundTimer=0;
	}
	Lose::~Lose(){
		delete _flower;
	}
	void Lose::run(){
		input();
		update();
		draw();
	}
	void Lose::input(){
		if(_flower->getDeath()==true){
			mousePos=GetMousePosition();
			if(CheckCollisionPointRec(mousePos,_playAgainButtonRec)){
				mouseInButton=play;
				if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
					gameState=onGameplay;
				}
			}
			else if(CheckCollisionPointRec(mousePos,_menuButtonRec)){
				mouseInButton=menu;
				if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
					gameState=onMenu;
				}
			}
			else if(CheckCollisionPointRec(mousePos,_exitButtonRec)){
				mouseInButton=exit;
				if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
					gameState=closeGame;
				}
			}
			else
				mouseInButton=nothing;
		}
	}
	void Lose::update(){
		if(soundPlayed==false){
			soundTimer+=GetFrameTime();
			if(soundTimer>=maxSoundTimer){
				soundTimer=0;
				PlaySound(_loseSound);
				soundPlayed=true;
			}
		}
	}
	void Lose::draw(){
		DrawTexture(_skySprite,0,0,WHITE);
		_flower->deadAnim();
		DrawTexture(_windowSprite,0,0,WHITE);
		if(_flower->getDeath()==true){
			DrawTexture(_loseText,0,0,WHITE);
			DrawTexture(_endButtons,0,0,WHITE);

			switch(mouseInButton){
			case play:
				DrawTexture(_playAgainButtonSprite,0,0,WHITE);
				break;
			case menu:
				DrawTexture(_menuButtonSprite,0,0,WHITE);
				break;
			case exit:
				DrawTexture(_exitButtonSprite,0,0,WHITE);
				break;
			case nothing:
				break;
			}
		}
	}
}