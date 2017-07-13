#ifndef SGL_H
#define SGL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <shader.h>
#include <shape.h>

#define SGL_TRIANGLE 1;
#define SGL_SQUARE 2;

struct sgl_color {
	float r;
	float g;
	float b;
};

void init_SGL ();
void destruct_SGL ();

bool shouldClose ();
void FlipShouldClose ();
void sgl_set_clear_color (sgl_color color);
void register_key_event (void (* keyFuncPtr)(GLFWwindow *, int, int, int, int));
void render ();

void sgl_render_add_texture (sgl_shape *o);
void sgl_render_add_color (sgl_shape *o);

#endif
