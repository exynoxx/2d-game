#ifndef SHADER_H
#define SHADER_H

#include <GLFW/glfw3.h>
#include <iostream>

class shader {
public:
	shader (char *vs, char *fs);
	shader () {};
	unsigned int create_shader_program (char *vs, char *fs);
	unsigned int ID;

private:
	char *read_file (char *name);

};

#endif
