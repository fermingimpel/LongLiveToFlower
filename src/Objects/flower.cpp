#include "flower.h"

#include "Objects/common_things.h"
#include "Sprites/sprites.h"

namespace LudumDare{

	static int actualPlant=0;
	static const int maxPlants=7;

	enum FlowerAction{
		growFlower,
		deadFlower,
		keepFlower
	};

	FlowerAction action;

	Flower::Flower(){
		for(int i=0;i<maxPlants;i++)
			_plantSprites[i]=plantsSprites[i];
		actualPlant=0;
		action=keepFlower;
	}
	Flower::~Flower(){

	}
	void Flower::update(){
		if(action==growFlower){
			actualPlant++;
			if(actualPlant>=maxPlants){
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
	void Flower::grow(){
		action=growFlower;
	}
	void Flower::dead(){
		action=deadFlower;
	}

}