#include <sGL.h>

/* WINDOW */
GLFWwindow* window;

/* SHADER/RENDER */
shader shader_texture;
shader shader_color;
std::vector<sgl_shape *> objs_texture;
std::vector<sgl_shape *> objs_color;

/* SETTINGS */
bool close = false;
sgl_color default_color = {0.2f, 0.3f, 0.3f};

double lastTime = glfwGetTime();
int frames;

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
    shader_texture.create_shader_program ("shaders/vertex.vs", "shaders/texture.fs");
    shader_color.create_shader_program ("shaders/vertex.vs", "shaders/color.fs");
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

void sgl_set_clear_color (sgl_color color) {
    default_color = color;
}

void register_key_event (void (* keyFuncPtr)(GLFWwindow *, int, int, int, int)) {
    glfwSetKeyCallback(window, keyFuncPtr);
}

void fps () {

     double currentTime = glfwGetTime();
     frames++;
     if ( currentTime - lastTime >= 1.0 ){ // If last prinf() was more than 1 sec ago
         std::cout << frames << std::endl;
         //glfwSetWindowTitle (window, frames);
         frames = 0;
         lastTime += 1.0;
     }
}

/* --- SQUARE --- */
sgl_shape *sgl_create_square_color (unsigned int hex) {
    static sgl_shape tmp (&shader_color, 2, NULL, hex);
    objs_color.push_back (&tmp);
    return &tmp;
}

sgl_shape *sgl_create_square_texture (char *filname) {
    static sgl_shape tmp (&shader_texture, 2,filname);
    objs_texture.push_back (&tmp);
    return &tmp;
}

/* --- TRIANGLE --- */
sgl_shape *sgl_create_triangle_color (unsigned int hex) {
    static sgl_shape tmp (&shader_color, 1, NULL, hex);
    objs_color.push_back (&tmp);
    return &tmp;
}

sgl_shape *sgl_create_triangle_texture (char *filname) {
    static sgl_shape tmp (&shader_texture, 1,filname);
    objs_texture.push_back (&tmp);
    return &tmp;
}



void render (){
    glClearColor(default_color.r, default_color.g, default_color.b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shader_texture.ID);
    for (int i = 0; i < objs_texture.size (); i++) {
        objs_texture[i]->render ();
    }

    glUseProgram(shader_color.ID);
    for (int i = 0; i < objs_color.size (); i++) {
        objs_color[i]->render ();
    }

    fps ();
    glfwSwapBuffers(window);
    glfwPollEvents();
}
