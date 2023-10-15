debug: test
	@builds/MandelbrotSet
test: src/*.cpp
	@g++ src/*.cpp -o builds/MandelbrotSet -lraylib
clean:
	rm builds/* -r
	rm temp -r