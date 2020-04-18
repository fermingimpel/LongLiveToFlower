#ifndef COMMON_THINGS_H
#define COMMON_THINGS_H

namespace LudumDare{

	enum GameStates{
		onMenu,
		onGameplay,
		onEnd,
		onCredits,
		closeGame
	};

	enum Final{
		win,
		lose
	};

	extern GameStates gameState;
	extern Final final;
	extern const int screenWidth;
	extern const int screenHeight;

}

#endif