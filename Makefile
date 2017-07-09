#Makefile = macOS only

all: compile run

run:
	./main

compile:
	g++-7 -o main src/*.cpp src/*.c -O2 -Iinclude -I/usr/local/include -L /usr/local/lib/ -lglfw3 -lSOIL -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
