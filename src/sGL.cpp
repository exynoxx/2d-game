#include <sGL.h>

GLFWwindow* window;
unsigned int shaderID;
std::vector<sgl_triangle *> objs;
bool close = false;
sgl_color default_color = {0.2f, 0.3f, 0.3f};

void init_SGL()
{
    //init
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    //window init
    window = glfwCreateWindow(600, 600, "sGL", NULL, NULL);
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

bool shouldClose () {
    return (close | glfwWindowShouldClose(window));
}

void FlipShouldClose () {
    close = !close;
}

void rectangle_add (sgl_triangle *o) {
    objs.push_back (o);
}

void sgl_set_clear_color (sgl_color color) {
    default_color = color;
}

void register_key_event (void (* keyFuncPtr)(GLFWwindow *, int, int, int, int)) {
    glfwSetKeyCallback(window, keyFuncPtr);
}

void render (){
    glClearColor(default_color.r, default_color.g, default_color.b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderID);
    for (int i = 0; i < objs.size (); i++) {
        objs[i]->render ();
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}
