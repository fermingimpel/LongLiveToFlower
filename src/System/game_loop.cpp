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
		_menu = NULL;
		_game = NULL;
		_end = NULL;
		_music = NULL;

		_menu=new Menu();
		_music=new Music();

	}
	Game_Loop::~Game_Loop(){
		if(_menu!=NULL)
			delete _menu;
		if(_game!=NULL)
			delete _game;
		if(_end!=NULL)
			delete _end;
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
				if(_end!=NULL){
					delete _end;
					_end=NULL;
				}

				if(_menu!=NULL){
					_menu->run();
				}
				break;
			
			case onGameplay:
				if(_game==NULL)
					_game=new Game();
				else if(_game!=NULL)
					_game->run();
				break;

			case onEnd:
				if(_end==NULL)
					_end=new End();
				else if(_end!=NULL)
					;
				break;

			}

			EndDrawing();
		}
	}

}