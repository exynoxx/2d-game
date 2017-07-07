#ifndef SGL_H
#define SGL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class shader {

public:
	void create_shader_program ();
	void use ();

private:
	char *read_file (char *name);
	int shaderProgram;
} shader;

class object {
	public:
		object ();
		void render ();
	private:
		unsigned int VBO, VAO;
		unsigned int texture;

};

GLFWwindow* window;

int init_SGL ();
void destruct_SGL ();

#endif
