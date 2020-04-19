#include "tutorial.h"

#include "Objects/common_things.h"
#include "Sprites/sprites.h"

namespace LudumDare{

	enum TutorialButtons{
		back,
		next,
		nothing
	};
	static TutorialButtons mouseInButton;
	Vector2 mousePos;

	static int actualSprite=0;
	static int maxSprites=6;

	static const int buttonsWidth=132;
	static const int buttonsHeight=53;
	static const int buttonsY=427;
	static const int backButtonX=10;
	static const int nextButtonX=370;
	Tutorial::Tutorial(){
		for(int i=0;i<maxSprites;i++)
			_tutorialSprites[i]=tutorialSprites[i];
		_buttonsSprite=onTutorialButtonsSprite;
		_backButtonSprite=backButtonSprite;
		_nextButtonSprite=nextButtonSprite;
		actualSprite=0;

		_backButtonRec.x=backButtonX;
		_backButtonRec.y=buttonsY;
		_backButtonRec.width=buttonsWidth;
		_backButtonRec.height=buttonsHeight;

		_nextButtonRec.x=nextButtonX;
		_nextButtonRec.y=buttonsY;
		_nextButtonRec.width=buttonsWidth;
		_nextButtonRec.height=buttonsHeight;
	}
	Tutorial::~Tutorial(){

	}
	void Tutorial::run(){
		input();
		draw();
	}
	void Tutorial::input(){
		mousePos=GetMousePosition();

		if(CheckCollisionPointRec(mousePos,_backButtonRec)){
			mouseInButton=back;
			if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
				actualSprite--;
				if(actualSprite<0)
					gameState=onMenu;
			}
		}
		else if(CheckCollisionPointRec(mousePos,_nextButtonRec)){
			mouseInButton=next;
			if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
				actualSprite++;
				if(actualSprite>=maxSprites)
					gameState=onMenu;
			}
		}
		else{
			mouseInButton=nothing;
		}
	}
	void Tutorial::draw(){
		DrawTexture(_tutorialSprites[actualSprite],0,0,WHITE);
		DrawTexture(_buttonsSprite,0,0,WHITE);
		switch(mouseInButton){
		case back:
			DrawTexture(_backButtonSprite,0,0,WHITE);
			break;
		case next:
			DrawTexture(_nextButtonSprite,0,0,WHITE);
			break;
		case nothing:
			break;
		}
	}

}