#ifndef FLOWER_NEEDS_H
#define FLOWER_NEEDS_H

#include "raylib.h"

namespace LudumDare{

	class Flower_Needs{
		Texture2D _sunSprite;
		Texture2D _waterSprite;
		Texture2D _needSunSprite;
		Texture2D _needWaterSprite;
		bool _charging;
		float _sunCharge;
		float _waterCharge;
		Rectangle _sunChargeRec;
		Rectangle _waterChargeRec;
	public:
		Flower_Needs();
		~Flower_Needs();
		void input();
		void update();
		void draw();
		bool getNeedSun();
		bool getNeedWater();
		float getSunCharge();
		float getWaterCharge();
	};

}

#endif