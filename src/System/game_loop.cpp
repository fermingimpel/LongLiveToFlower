#include "game_loop.h"

#include "raylib.h"

#include "Objects/common_things.h"
#include "Sprites/sprites.h"

namespace LudumDare{

	Game_Loop::Game_Loop(){
		InitWindow(screenWidth,screenHeight,"Long Live To Flower LD46");
		SetExitKey(KEY_VOLUME_DOWN);
		InitAudioDevice();
		loadSprites();
		
		gameState=onMenu;
		_menu=NULL;
		_game=NULL;
		_tutorial=NULL;
		_lose=NULL;
		_win=NULL;

		_menu=new Menu();
	}
	Game_Loop::~Game_Loop(){
		if(_menu!=NULL)
			delete _menu;
		if(_game!=NULL)
			delete _game;
		if(_tutorial!=NULL)
			delete _tutorial;
		if(_lose!=NULL)
			delete _lose;
		if(_win!=NULL)
			delete _win;

		unloadSprites();
		CloseAudioDevice();
		CloseWindow();
	}
	void Game_Loop::play(){
		while(gameState!=closeGame&&!WindowShouldClose()){
			BeginDrawing();
			ClearBackground(BLACK);
			switch(gameState){
			case onMenu:
				if(_game!=NULL){
					delete _game;
					_game=NULL;
				}
				if(_tutorial!=NULL){
					delete _tutorial;
					_tutorial=NULL;
				}
				if(_lose!=NULL){
					delete _lose;
					_lose=NULL;
				}
				if(_win!=NULL){
					delete _win;
					_win=NULL;
				}

				if(_menu!=NULL){
					_menu->run();
				}
				break;

			case onGameplay:
				if(_tutorial!=NULL){
					delete _tutorial;
					_tutorial=NULL;
				}
				if(_lose!=NULL){
					delete _lose;
					_lose=NULL;
				}
				if(_win!=NULL){
					delete _win;
					_win=NULL;
				}

				if(_game==NULL)
					_game=new Game();
				else if(_game!=NULL)
					_game->run();
				break;
			case onTutorial:
				if(_game!=NULL){
					delete _game;
					_game=NULL;
				}
				if(_lose!=NULL){
					delete _lose;
					_lose=NULL;
				}
				if(_win!=NULL){
					delete _win;
					_win=NULL;
				}

				if(_tutorial==NULL)
					_tutorial=new Tutorial();
				else if(_tutorial!=NULL)
					_tutorial->run();
				break;
			case onEnd:
				if(final==lose){
					if(_game!=NULL){
						delete _game;
						_game=NULL;
					}
					if(_tutorial!=NULL){
						delete _tutorial;
						_tutorial=NULL;
					}
					if(_win!=NULL){
						delete _win;
						_win=NULL;
					}
					if(_lose==NULL)
						_lose=new Lose();
					else if(_lose!=NULL)
						_lose->run();
				}
				else if(final==win){
					if(_game!=NULL){
						delete _game;
						_game=NULL;
					}
					if(_tutorial!=NULL){
						delete _tutorial;
						_tutorial=NULL;
					}
					if(_lose!=NULL){
						delete _lose;
						_lose=NULL;
					}

					if(_win==NULL)
						_win=new Win();
					else if(_win!=NULL)
						_win->run();
				}
				break;
			}
			EndDrawing();
		}
	}

}