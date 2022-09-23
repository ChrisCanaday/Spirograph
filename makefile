all: Spiro

Spiro: main.o
	g++ -o bin/Spiro main.o

main.o:
	g++ -c src/main.cpp

clean:
	rm -rf bin/Spiro main.o