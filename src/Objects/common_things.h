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

	extern GameStates gameState;
	extern Final final;
	extern FlowerStates flowerState;
	extern const int screenWidth;
	extern const int screenHeight;

}

#endif