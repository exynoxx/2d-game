#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <fstream>
#include <sGL.h>

class shader {

public:
	void create_shader_program ();
	void use ();

private:
	char *read_file (char *name);
	int shaderProgram;
} shader;

#endif
