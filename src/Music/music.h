#ifndef MUSIC_H
#define MUSIC_H

#include "raylib.h"

namespace LudumDare{

	class GameMusic{
		 Music _song;
	public:
		GameMusic();
		~GameMusic();
		void play();
	};

}

#endif