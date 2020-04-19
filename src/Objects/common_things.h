#ifndef COMMON_THINGS_H
#define COMMON_THINGS_H

namespace LudumDare{

	enum GameStates{
		onMenu,
		onGameplay,
		onEnd,
		onTutorial,
		closeGame
	};

	enum Final{
		win,
		lose
	};

	enum FlowerStates{
		alive,
		dead,
		growing
	};

	enum FlowerAction{
		growFlower,
		deadFlower,
		keepFlower
	};

	enum FlowerPhase{
		death=0,
		first=1, 
		second=2, 
		third=3, 
		fourth=4, 
		fifth=5, 
		sixth=6, 
		seventh=7
	};

	extern GameStates gameState;
	extern Final final;
	extern FlowerStates flowerState;
	extern FlowerAction action;
	extern FlowerPhase phase;
	extern const int screenWidth;
	extern const int screenHeight;

}

#endif