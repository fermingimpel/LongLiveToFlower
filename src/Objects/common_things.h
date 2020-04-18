#ifndef COMMON_THINGS_H
#define COMMON_THINGS_H

namespace LudumDare{

	enum GameStates{
		onMenu,
		onGameplay,
		onEnd,
		closeGame
	};

	extern GameStates gameState;
	extern int screenWidth;
	extern int screenHeight;

}

#endif