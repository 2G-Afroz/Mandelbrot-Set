#include<raylib.h>
#include<iostream>
using namespace std;

void mandelFunction(vector<Vector2> &pos, float x, float y){
				// Imaginary num "x + iy"

				for(int i=0;i<20;i++){
								pos[i].x = x;
								pos[i].y = y;

								// temp
								float a = x*x - y*y;
								float b = 2*x*y;
								x = a;
								y = b;
				}
}

void printArrVal(vector<float> pos){
				for(int i=0;i<20;i++){
								DrawText(TextFormat("%f", pos[i]), 10, 40+20*i, 20, WHITE);
				}
}

int main(){
	int windowWidth = 1200;
	int windowHeight = 850; 
	InitWindow(windowWidth, windowHeight,"MandelbrotSet");

	Vector2 centre = {600,425};
	vector<Vector2> pos(20);

	while(!WindowShouldClose()){
    ClearBackground(BLACK);
		BeginDrawing();
				DrawCircle(centre.x, centre.y, 1,RED);
				// Mouse Work
				float mouseX = (GetMouseX()-centre.x)/200.0f;
				float mouseY = (centre.y-GetMouseY())/200.0f;
				
				DrawText(TextFormat("MouseX: %f", mouseX), 10, 10, 30, WHITE); 
				DrawText(TextFormat("MouseY: %f", mouseY), 10, 40, 30, WHITE); 
				// Mandel Function
				mandelFunction(pos, mouseX, mouseY);

				// Drawing circle border
				DrawCircleLines(centre.x, centre.y, 200, RED);

				// Draw line
				for(int i=0;i<19;i++){
								DrawLine(centre.x+pos[i].x*200, centre.y-pos[i].y*200,
																centre.x+pos[i+1].x*200, centre.y-pos[i+1].y*200,
																WHITE); 
				}
								

				// Drawing circles
				for(int i=0;i<20;i++){
								DrawCircle(centre.x + pos[i].x*200, centre.y-pos[i].y*200, 4, GREEN);
				}
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
