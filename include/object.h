#ifndef OBJECT_H
#define OBJECT_H

struct sgl_object {
	unsigned int VBO;
	unsigned int VAO;
	unsigned int texture;
	glm::mat4 transform;
};

#endif
