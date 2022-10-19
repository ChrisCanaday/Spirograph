all: 
	g++ -o bin/Spiro src/main.cpp include/main.h
	sh run.sh examples/bohrsatom.txt examples/bohrsatom.jpg
	sh run.sh examples/colorful.txt examples/colorful.jpg
	sh run.sh examples/colorfulstar.txt examples/colorfulstar.jpg
	sh run.sh examples/sunflower.txt examples/sunflower.jpg
	sh run.sh examples/youtube.txt examples/youtube.jpg
clean:
	rm -rf bin/Spiro main.o