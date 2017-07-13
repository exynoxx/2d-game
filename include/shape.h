#ifndef SHAPE_H
#define SHAPE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <shader.h>
#include <SOIL/SOIL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class sgl_shape {

public:
	sgl_shape (int mode, char *filname = NULL, unsigned int hexcolor = 0xFFffFF);
	~sgl_shape ();

	void move (float x, float y);
	void rotate (float degree);
	void scale (float factor);
	void render ();
private:
	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;
	unsigned int texture;
	unsigned int mode;
	glm::mat4 transform;
};

extern void sgl_render_add_texture (sgl_shape *o);
extern void sgl_render_add_color (sgl_shape *o);

#endif
