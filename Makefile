all: compile run

run:
	./main

compile:
	cc -v -o main src/main.c src/glad.c -Iinclude -I/usr/local/include -L /usr/local/lib/ -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo


	# -I/usr/local/include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
