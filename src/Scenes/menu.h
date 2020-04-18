#ifndef MENU_H
#define MENU_H

#include "raylib.h"

namespace LudumDare{

	class Menu{
		Rectangle _playRec;
		Rectangle _creditsRec;
		Rectangle _exitRec;
		Texture2D _menuSprite;
		Texture2D _playButtonSelected;
		Texture2D _creditsButtonSelected;
		Texture2D _exitButtonSelected;
	public:
		Menu();
		~Menu();
		void run();
		void input();
		void update();
		void draw();
	};

}

#endif