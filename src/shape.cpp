#include <shape.h>

unsigned int shaderConn;

sgl_shape::sgl_shape (int mode, char *filname, unsigned int hexcolor) {
	this->mode = mode;
	if (filname == NULL) {
		glGetUniformLocation(get_shaderID_color (), "transform");
	} else {
		glGetUniformLocation(get_shaderID_textue (), "transform");
	}

	float r = ((hexcolor >> 16) & 0xFF) / 255.0;
    float g = ((hexcolor >> 8) & 0xFF) / 255.0;
    float b = ((hexcolor) & 0xFF) / 255.0;


    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first,
	// then bind and set vertex buffer(s),
	// and then configure vertex attributes(s).
    glBindVertexArray(VAO);

	if (mode == 2) {

		float vertices[] = {
	         // positions           //color 	//texture coords
	         0.5f,  0.5f, 0.0f, 	r, g, b,	1.0f, 0.0f, // top right
	         0.5f, -0.5f, 0.0f, 	r, g, b,	1.0f, 1.0f, // bottom right
	        -0.5f, -0.5f, 0.0f, 	r, g, b,	0.0f, 1.0f, // bottom left
	        -0.5f,  0.5f, 0.0f, 	r, g, b,	0.0f, 0.0f  // top left
	    };

		unsigned int indices[] = {  //we start from 0!
		    0, 1, 3,   //first triangle
		    1, 2, 3    //second triangle
		};

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
	    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	} else {
		float vertices[] = {
			 //positions			//color		//texture coords
	        -0.5f, -0.5f, 0.0f, 	r, g, b,	0.0f, 1.0f,
	         0.5f, -0.5f, 0.0f, 	r, g, b,	1.0f, 1.0f,
	         0.0f,  0.5f, 0.0f, 	r, g, b,	0.5f, 0.0f
	    };

		unsigned int indices[] = {
		    0, 1, 2
		};
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
	    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	}

	//position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	//texture coord
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);



    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_LINEAR

	if (filname != NULL) {
		int width, height, nrChannels;
	    unsigned char *data = SOIL_load_image(filname, &width, &height, &nrChannels, 0);
	    if (data) {
	        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	        glGenerateMipmap(GL_TEXTURE_2D);
	    } else {
	        std::cout << "Failed to load texture" << std::endl;
	    }
	    SOIL_free_image_data(data);
	}


    // note that this is allowed, the call to glVertexAttribPointer registered VBO
	//as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO,
	// but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs
	//(nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);

	if (filname == NULL) {
		sgl_render_add_color (this);
	} else {
		sgl_render_add_texture (this);
	}
}

sgl_shape::~sgl_shape () {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void sgl_shape::move (float x, float y) {
	transform = glm::translate(transform, glm::vec3(x, y, 0.0f));
}

void sgl_shape::rotate (float degree) {
	transform = glm::rotate(transform, -glm::radians(degree), glm::vec3(0.0, 0.0, 1.0));
}

void sgl_shape::scale (float factor) {
	transform = glm::scale(transform, glm::vec3(factor, factor, factor));
}

void sgl_shape::render () {
	glUniformMatrix4fv(shaderConn, 1, GL_FALSE, glm::value_ptr(transform));
	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	if (mode == 2) {
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	} else {
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
	}
}
