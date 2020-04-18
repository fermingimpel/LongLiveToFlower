#ifndef FLOWER_H
#define FLOWER_H

#include "raylib.h"

#include "Objects/flower_needs.h"

namespace LudumDare{

	class Flower{
		Texture2D _plantSprites[7];
	public:
		Flower();
		~Flower();
		void update();
		void draw();
		void grow();
		void dead();
	};

}

#endif