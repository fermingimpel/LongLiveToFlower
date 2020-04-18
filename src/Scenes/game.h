#ifndef GAME_H
#define GAME_H

#include "raylib.h"

#include "Objects/flower.h"
#include "Objects/flower_needs.h"

namespace LudumDare{

	class Game{
		Texture2D _windowSprite;
		Texture2D _skySprite;
		Flower* _flower;
		Flower_Needs* _flowerNeeds;
	public:
		Game();
		~Game();
		void run();
		void input();
		void update();
		void draw();
	};

}

#endif