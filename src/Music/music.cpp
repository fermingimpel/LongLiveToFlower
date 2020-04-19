#include "music.h"

namespace LudumDare{

	GameMusic::GameMusic(){
		_song=LoadMusicStream("res/Assets/Sounds/Song.ogg");
		PlayMusicStream(_song);
	}
	GameMusic::~GameMusic(){
		StopMusicStream(_song);
		UnloadMusicStream(_song);
	}
	void GameMusic::play(){
		UpdateMusicStream(_song);
	}
}