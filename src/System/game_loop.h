#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "Scenes/menu.h"
#include "Scenes/game.h"
#include "Scenes/end.h"
#include "Music/music.h"

namespace LudumDare{

	class Game_Loop{
		Menu* _menu;
		Game* _game;
		End* _end;
		Music* _music;
	public:
		Game_Loop();
		~Game_Loop();
		void play();
	};

}

#endif