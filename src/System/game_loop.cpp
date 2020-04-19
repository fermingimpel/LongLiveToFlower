#include "game_loop.h"

#include "raylib.h"

#include "Objects/common_things.h"
#include "Sprites/sprites.h";

namespace LudumDare{

	Game_Loop::Game_Loop(){
		InitWindow(screenWidth,screenHeight,"Long Live To Flower");
		SetExitKey(KEY_VOLUME_DOWN);
		InitAudioDevice();
		loadSprites();

		gameState=onMenu;
		_menu=NULL;
		_game=NULL;
		_lose=NULL;
		_win=NULL;
		_music=NULL;

		_menu=new Menu();
		_music=new Music();

	}
	Game_Loop::~Game_Loop(){
		if(_menu!=NULL)
			delete _menu;
		if(_game!=NULL)
			delete _game;
		if(_lose!=NULL)
			delete _lose;
		if(_win!=NULL)
			delete _win;
		if(_music!=NULL)
			delete _music;

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

			case onEnd:
				if(final==lose){
					if(_game!=NULL){
						delete _game;
						_game=NULL;
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