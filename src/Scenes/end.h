#ifndef END_H
#define END_H

#include "raylib.h"

#include "Objects/flower.h"

namespace LudumDare{

	class End{
		Flower* _flower;
		Texture2D _windowSprite;
		Texture2D _skySprite;
		Texture2D _endButtons;
		Texture2D _playAgainButtonSprite;
		Texture2D _menuButtonSprite;
		Texture2D _exitButtonSprite;
		Texture2D _loseText;
		Rectangle _playAgainButtonRec;
		Rectangle _menuButtonRec;
		Rectangle _exitButtonRec;
	public:
		End();
		~End();
		void run();
		void input();
		void draw();
	};

}

#endif