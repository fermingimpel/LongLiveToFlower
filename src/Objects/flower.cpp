#include "flower.h"

#include "Objects/common_things.h"
#include "Sprites/sprites.h"

namespace LudumDare{

	static int actualPlant=0;
	static const int maxPlants=7;

	static float timerDead=0;
	static float maxTimerDead=0.2f;

	Flower::Flower(){
		for(int i=0;i<maxPlants;i++)
			_plantSprites[i]=plantsSprites[i];
		_plantDead=plantDead;
		actualPlant=0;
		_chargeToGrow=85;
		_chargeToDie=5;
		timerDead=0;
		_death=false;
		action=keepFlower;
		phase=first;
	}
	Flower::~Flower(){
	}
	void Flower::update(){
		if(action==growFlower){
			actualPlant++;

			if(phase==first)
				phase=second;
			if(phase==second)
				phase=third;
			if(phase==third)
				phase=fourth;
			if(phase==fourth)
				phase=fifth;
			if(phase==fifth)
				phase=sixth;
			if(phase==sixth)
				phase=seventh;

			if(actualPlant>=maxPlants && phase==seventh){
				final=win;
				gameState=onEnd;
			}
			action=keepFlower;
		}
		else if(action==deadFlower){
			final=lose;
			gameState=onEnd;
			action=keepFlower;
		}
	}
	void Flower::draw(){
		DrawTexture(_plantSprites[actualPlant],0,0,WHITE);
	}
	float Flower::getChargeToGrow(){
		return _chargeToGrow;
	}
	float Flower::getChargeToDie(){
		return _chargeToDie;
	}
	void Flower::grow(){
		action=growFlower;
	}
	void Flower::dead(){
		action=deadFlower;
	}
	void Flower::setDeatFlower(){
		actualPlant=phase-1;
		phase=death;
		timerDead=0;
	}
	void Flower::deadAnim(){
		if(actualPlant>=0){
			DrawTexture(_plantSprites[actualPlant],0,0,WHITE);
		
			timerDead+=GetFrameTime();
			if(timerDead>=maxTimerDead){
				timerDead=0;
				actualPlant--;
			}
		}
		else if(actualPlant<0){
			DrawTexture(_plantDead,0,0,WHITE);
			_death=true;
		}
	}
	bool Flower::getDeath(){
		return _death;
	}

}