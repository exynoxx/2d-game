all: compile run

run:
	./main
	# -I/usr/local/include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

compile:
	echo "####################### COMPILE #######################\n\n\n\n\n"
	g++-7 -o main src/*.cpp src/*.c -Iinclude -I/usr/local/include -L /usr/local/lib/ -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
