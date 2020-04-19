#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "raylib.h"

namespace LudumDare{

	class Tutorial{
		Texture2D _tutorialSprites[6];
		Texture2D _buttonsSprite;
		Texture2D _backButtonSprite;
		Texture2D _nextButtonSprite;
		Rectangle _backButtonRec;
		Rectangle _nextButtonRec;
	public:
		Tutorial();
		~Tutorial();
		void run();
		void input();
		void draw();
	};

}

#endif