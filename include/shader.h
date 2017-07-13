#ifndef SHADER_H
#define SHADER_H

#include <GLFW/glfw3.h>
#include <iostream>

unsigned int create_shader_program (char *vs, char *fs);
unsigned int get_shaderID_textue ();
unsigned int get_shaderID_color ();
void set_shaderID_textue (unsigned int id);
void set_shaderID_color (unsigned int id);

#endif
