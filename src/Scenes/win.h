#ifndef WIN_H
#define WIN_H

#include "raylib.h"

namespace LudumDare{

	class Win{
		Texture2D _winSprites[9];
		Sound _winSound;
	public:
		Win();
		~Win();
		void run();
		void update();
		void draw();
	};

}

#endif