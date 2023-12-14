debug: test
	@builds/MandelbrotSet
test: src/*.cpp
	@g++ src/*.cpp -o builds/MandelbrotSet -L./lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -std=c++11
clean:
	rm builds/* -r
	rm temp -r