#include <glad/glad.h>
#include <sGL.h>


//std::vector<object> v;

int init_SGL () {
	//init
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    //window init
    window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL){
		printf("Failed to create GLFW window\n");
	    glfwTerminate();
	    return 1;
	}
	glfwMakeContextCurrent(window);
    //glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    	printf("Failed to create GLFW window\n");
    	return 1;
	}

    //start
    shader.create_shader_program ();
    return 0;
}

void destruct_SGL () {
    //glDeleteVertexArrays(1, &VAO);
    //glDeleteBuffers(1, &VBO);

    glfwTerminate();
}
