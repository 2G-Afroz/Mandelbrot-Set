#include<raylib.h>

int main(){
	int windowWidth = 700;
	int windowHeight = 700; 
	InitWindow(windowWidth, windowHeight,"MandelbrotSet");

	ClearBackground(BLACK);

	while(!WindowShouldClose()){
		BeginDrawing();
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
