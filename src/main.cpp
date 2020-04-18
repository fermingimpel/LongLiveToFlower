#include "raylib.h"

void main(){

	InitWindow(512,512,"asd");

	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(BLACK);
		DrawRectangle(15,15,100,100,RED);
		EndDrawing();
	}

}