#include <sGL.h>

GLFWwindow* window;
unsigned int shaderID;
std::vector<sgl_triangle> objs;

/*

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESC && action == GLFW_PRESS)
        activate_airship();
}*/

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
    //glfwSetKeyCallback(window, key_callback);

    //glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to create GLFW window" << std::endl;
    	return;
	}

    //start
    create_shader_program ();
    shaderID = get_shader ();
}

void destruct_SGL () {
    glfwTerminate();
}

void render (){
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderID);
    for (int i = 0; i < objs.size (); i++) {
        objs[i].render ();
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}
