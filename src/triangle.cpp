#include <triangle.h>

unsigned int shaderConnection;

sgl_triangle::sgl_triangle () {
	int shaderID = get_shader ();
    shaderConnection = glGetUniformLocation(shaderID, "transform");

	//invert-y: invert all y-coordinats
	float vertices[] = {
        -0.5f, -0.5f, 0.0f,     0.0f, 1.0f,
         0.5f, -0.5f, 0.0f,     1.0f, 1.0f,
         0.0f,  0.5f, 0.0f,     0.5f, 0.0f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first,
	// then bind and set vertex buffer(s),
	// and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_LINEAR

    int width, height, nrChannels;
    unsigned char *data = SOIL_load_image("src/tree.jpg", &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    SOIL_free_image_data(data);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO
	//as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO,
	// but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs
	//(nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
}

sgl_triangle::~sgl_triangle () {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void sgl_triangle::move (float x, float y) {
	transform = glm::translate(transform, glm::vec3(x, y, 0.0f));
}

void sgl_triangle::rotate (float degree) {
	transform = glm::rotate(transform, -glm::radians(degree), glm::vec3(0.0, 0.0, 1.0));
}

void sgl_triangle::scale (float factor) {
	transform = glm::scale(transform, glm::vec3(factor, factor, factor));
}

void sgl_triangle::render () {
	glUniformMatrix4fv(shaderConnection, 1, GL_FALSE, glm::value_ptr(transform));
	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
