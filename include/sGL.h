#ifndef SGL_H
#define SGL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <shader.h>
#include <triangle.h>

struct sgl_color {
	float r;
	float g;
	float b;
};

void init_SGL ();
void destruct_SGL ();

bool shouldClose ();
void sgl_set_clear_color (sgl_color color);
void render ();

void rectangle_add (sgl_triangle *o);

#endif
