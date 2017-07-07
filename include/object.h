#ifndef OBJECT_H
#define OBJECT_H

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <sGL.h>

class object {
	public:
		object ();
		void render ();
	private:
		unsigned int VBO, VAO;
		unsigned int texture;

};

#endif
