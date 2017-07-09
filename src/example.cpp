#include <sGL.h>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        FlipShouldClose ();
}

int main (){

	init_SGL ();
	register_key_event (key_callback);

	sgl_triangle t1;
	t1.move (-0.5, 0.5);
	t1.scale (1.2);
	t1.rotate (90);
    rectangle_add (&t1);

	sgl_triangle t2;
	t2.move (0.5,-0.5);
	t2.scale (0.2);
	t2.rotate (-50);
    rectangle_add (&t2);



    while (!shouldClose()) {
        render ();
		sgl_set_clear_color ({(float)glm::sin(glfwGetTime()*3.5), (float)glm::sin((glfwGetTime()-0.5)*1),(float)glm::sin(glfwGetTime()*1.8)});
    }
    destruct_SGL ();

}
