#include "menu.h"

#include "Objects/common_things.h"
#include "Sprites/sprites.h"

namespace LudumDare{

	static enum ButtonsMenu{
		play,
		tutorial,
		exit,
		noButton
	};
	static ButtonsMenu mouseInButton;
	static Vector2 mousePos;

	static const float buttonsWidth=246;
	static const float buttonsHeight=53;
	static const float buttonsX=134;
	static const float playButtonY=173;
	static const float tutorialButtonY=238;
	static const float exitButtonY=304;

	Menu::Menu(){
		mouseInButton=noButton;
		_menuSprite=menuSprite;
		_playButtonSelected=playButtonSprite;
		_tutorialButtonSelected=tutorialButtonSprite;
		_exitButtonSelected=exitButtonSprite;

		_playRec.x=buttonsX;
		_playRec.y=playButtonY;
		_playRec.width=buttonsWidth;
		_playRec.height=buttonsHeight;

		_tutorialRec.x=buttonsX;
		_tutorialRec.y=tutorialButtonY;
		_tutorialRec.width=buttonsWidth;
		_tutorialRec.height=buttonsHeight;

		_exitRec.x=buttonsX;
		_exitRec.y=exitButtonY;
		_exitRec.width=buttonsWidth;
		_exitRec.height=buttonsHeight;
		
	}
	Menu::~Menu(){
		
	}
	void Menu::run(){
		input();
		draw();
	}
	void Menu::input(){
		mousePos=GetMousePosition();

		if(CheckCollisionPointRec(mousePos,_playRec)){
			mouseInButton=play;
			if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
				gameState=onGameplay;
			}
		}
		else if(CheckCollisionPointRec(mousePos,_tutorialRec)){
			mouseInButton=tutorial;
			if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
				gameState=onTutorial;
			}
		}
		else if(CheckCollisionPointRec(mousePos,_exitRec)){
			mouseInButton=exit;
			if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
				gameState=closeGame;
			}
		}
		else{
			mouseInButton=noButton;
		}

	}
	void Menu::draw(){
		DrawTexture(_menuSprite,0,0,WHITE);
		switch(mouseInButton){
		case play:
			DrawTexture(_playButtonSelected,0,0,WHITE);
			break;
		case tutorial:
			DrawTexture(_tutorialButtonSelected,0,0,WHITE);
			break;
		case exit:
			DrawTexture(_exitButtonSelected,0,0,WHITE);
			break;
		case noButton:
			break;
		}
	}

}