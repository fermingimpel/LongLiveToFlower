#ifndef FLOWER_H
#define FLOWER_H

#include "raylib.h"

namespace LudumDare{

	class Flower{
		Texture2D _plantSprites[7];
		Texture2D _plantDead;
		float _chargeToGrow;
		float _chargeToDie;
		bool _death;
		Sound _growSound;
		Sound _deadSound;
	public:
		Flower();
		~Flower();
		void update();
		void draw();
		float getChargeToGrow();
		float getChargeToDie();
		void grow();
		void dead();
		void setDeatFlower();
		void deadAnim();
		bool getDeath();
	};

}

#endif