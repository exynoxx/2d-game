#include <sGL.h>

GLFWwindow* window;
int shaderID;
unsigned int shaderConnection;

std::vector<sgl_object> objs;

void init_SGL()
{
    //init
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    //window init
    window = glfwCreateWindow(800, 600, "sGL", NULL, NULL);
	if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
	    glfwTerminate();
	    return;
	}
	glfwMakeContextCurrent(window);
    //glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to create GLFW window" << std::endl;
    	return;
	}

    //start
    create_shader_program ();
    shaderID = get_shader ();
    shaderConnection = glGetUniformLocation(shaderID, "transform");
}

void render (){
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderID);
    for (int i = 0; i < objs.size (); i++) {
        glUniformMatrix4fv(shaderConnection, 1, GL_FALSE, glm::value_ptr(objs[i].transform));
        glBindTexture(GL_TEXTURE_2D, objs[i].texture);
        glBindVertexArray(objs[i].VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void create_triangle () {

    unsigned int VAO;
    unsigned int VBO;
    unsigned int texture;

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,     0.0f, 0.0f,
         0.5f, -0.5f, 0.0f,     1.0f, 0.0f,
         0.0f,  0.5f, 0.0f,     0.5f, 1.0f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
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
    stbi_set_flip_vertically_on_load(1);
    unsigned char *data = stbi_load("src/tree.jpeg", &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);

    sgl_object tmp;
    tmp.VAO = VAO;
    tmp.VBO = VBO;
    tmp.texture = texture;

    objs.push_back (tmp);
}


void destruct_SGL () {

    for (int i = 0; i < objs.size (); i++) {
        glDeleteVertexArrays(1, &objs[i].VAO);
        glDeleteBuffers(1, &objs[i].VBO);
    }

    glfwTerminate();
}

void move (sgl_object *o, float x, float y) {
    o->transform = glm::translate(o->transform, glm::vec3(x, y, 0.0f));
}

//degree
void rotate (sgl_object *o, float degree) {
    o->transform = glm::rotate(o->transform, glm::radians(degree), glm::vec3(0.0, 0.0, 1.0));
}

void scale (sgl_object *o, float factor) {
    o->transform = glm::scale(o->transform, glm::vec3(factor, factor, factor));
}

int main (){

	init_SGL ();
    create_triangle ();
    create_triangle ();
    create_triangle ();
    move (&objs[0], -0.5, -0.5);
    move (&objs[1], 0.3, 0.5);
    move (&objs[2], 0.5, -0.5);
    rotate (&objs[1], 60);
    scale (&objs[2], 0.5);

    while (1) {
        render ();
    }
    destruct_SGL ();

}
