all: 
	g++ -o bin/Spiro src/main.cpp include/main.h

clean:
	rm -rf bin/Spiro main.o