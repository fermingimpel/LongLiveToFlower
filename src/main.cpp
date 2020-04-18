#include "System/game_loop.h"

using namespace LudumDare;

int main(void){
	Game_Loop* game=NULL;
	game=new Game_Loop();

	if(game!=NULL)
		game->play();

	if(game!=NULL)
		delete game;

}