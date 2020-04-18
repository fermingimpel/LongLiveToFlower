#include "game.h"

#include "Sprites/sprites.h"

namespace LudumDare{

	Game::Game(){
		_windowSprite=windowSprite;
		_skySprite=skySprite;
		_flower=NULL;
		_flowerNeeds=NULL;

		_flower=new Flower();
		_flowerNeeds=new Flower_Needs();
	}
	Game::~Game(){
		if(_flower!=NULL)
			delete _flower;
		if(_flowerNeeds!=NULL)
			delete _flowerNeeds;

	}
	void Game::run(){
		input();
		update();
		draw();
	}
	void Game::input(){
		if(_flowerNeeds!=NULL)
			_flowerNeeds->input();
	}
	void Game::update(){
		if(_flower!=NULL)
			_flower->update();
		if(_flowerNeeds!=NULL)
			_flowerNeeds->update();
	}
	void Game::draw(){
		DrawTexture(_skySprite,0,0,WHITE);
		
		if(_flower!=NULL)
			_flower->draw();
		if(_flowerNeeds!=NULL)
			_flowerNeeds->draw();


		DrawTexture(_windowSprite,0,0,WHITE);
	}

}