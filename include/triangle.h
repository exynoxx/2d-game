#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <shader.h>
#include <SOIL/SOIL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class sgl_triangle {

public:
	sgl_triangle ();
	~sgl_triangle ();

	void move (float x, float y);
	void rotate (float degree);
	void scale (float factor);
	void render ();
private:
	unsigned int VBO;
	unsigned int VAO;
	unsigned int texture;
	glm::mat4 transform;
};

#endif
