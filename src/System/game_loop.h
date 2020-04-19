#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "Scenes/menu.h"
#include "Scenes/game.h"
#include "Scenes/tutorial.h"
#include "Scenes/lose.h"
#include "Scenes/win.h"
#include "Music/music.h"

namespace LudumDare{

	class Game_Loop{
		Menu* _menu;
		Game* _game;
		Tutorial* _tutorial;
		Lose* _lose;
		Win* _win;
		Music* _music;
	public:
		Game_Loop();
		~Game_Loop();
		void play();
	};

}

#endif