#include<raylib.h>
#include<iostream>
using namespace std;

// This function is used to map a number
float map(float value, float fromMin, float fromMax, float toMin, float toMax) {
    // Ensure that the value is within the input range
    value = min(max(value, fromMin), fromMax);
    return (value - fromMin) / (fromMax - fromMin) * (toMax - toMin) + toMin;
}

int main(){
	int windowWidth = 1335;
	int windowHeight = 890; 
	InitWindow(windowWidth, windowHeight,"MandelbrotSet");

	float zoom = 1.0f;

	while(!WindowShouldClose()){
  	ClearBackground(WHITE);

		BeginDrawing();
			// Drawing each pixel
			for(int i=0;i<windowWidth;i++){
				for(int j=0;j<windowHeight;j++){

				  // This is value of z
					float x = 0;		// real part
					float y = 0;		// imaginary part
					// This is value of c
					float a = map(i, 0, windowWidth, -2*zoom, 1*zoom); // real part
          float b = map(j, 0, windowHeight, -1*zoom, 1*zoom);	// imaginary part

          int n = 0;

          while(n<255){
						float xx = x*x-y*y+a;
						float yy = 2*x*y+b;

						x = xx;
						y = yy;

						if(abs(x + y) >= 10.0f){
							break;
						}
						n++;
          }
					// n = map(n, 0, 100, 0, 256); // this mapping gives different border effect.
					// Coloring Pixels

					Color pixelColor = {(unsigned char)n, (unsigned char)n, (unsigned char)n, 255};
					DrawPixel(i,j,pixelColor);

				}
			}
			EndDrawing();
	}

	CloseWindow();

	return 0;
}
