all: compile run

run:
	./main

compile:
	gcc-7 -o main src/*.c -Iinclude -I/usr/local/include -L /usr/local/lib/ -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo


	# -I/usr/local/include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

cpp:
	echo "####################### COMPILE #######################\n\n\n\n\n"
	g++-7 -o main src_cpp2/*.cpp src_cpp2/*.c -Iinclude -I/usr/local/include -L /usr/local/lib/ -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
