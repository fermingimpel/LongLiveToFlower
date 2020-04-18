#ifndef FLOWER_H
#define FLOWER_H

#include "raylib.h"

#include "Objects/flower_needs.h"

namespace LudumDare{

	class Flower{
		Texture2D _plantSprites[7];
		float _chargeToGrow;
		float _chargeToDie;
	public:
		Flower();
		~Flower();
		void update();
		void draw();
		float getChargeToGrow();
		float getChargeToDie();
		void grow();
		void dead();
	};

}

#endif