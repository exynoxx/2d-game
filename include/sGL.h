#ifndef SGL_H
#define SGL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <shader.h>
#include <triangle.h>


void init_SGL ();
void destruct_SGL ();

void render ();

int main ();

#endif
