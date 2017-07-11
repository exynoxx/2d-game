#include <sGL.h>

sgl_triangle *t1;
sgl_triangle *t2;

float dist = 0.5;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS | action == GLFW_REPEAT) {
        switch (key) {
            case GLFW_KEY_ESCAPE:
                FlipShouldClose ();
                break;
            case GLFW_KEY_LEFT:
                t1->rotate (-20);
                break;
            case GLFW_KEY_RIGHT:
                t1->rotate (20);
                break;
            case GLFW_KEY_A:
                t1->move (-dist,0);
                break;
            case GLFW_KEY_D:
                t1->move (dist,0);
                break;
            case GLFW_KEY_W:
                t1->move (0, dist);
                break;
            case GLFW_KEY_S:
                t1->move (0, -dist);
                break;
            case GLFW_KEY_Q:
                t1->scale (0.9);
                break;
            case GLFW_KEY_E:
                t1->scale (1.1);
                break;
        }
    }
}

int main (){

	init_SGL ();
	register_key_event (key_callback);

    sgl_triangle a;
    sgl_triangle b;

    t1 = &a;
    t2 = &b;

	t1->move (-0.5, 0.5);
	t1->scale (1.2);
	t1->rotate (90);
    rectangle_add (t1);

	t2->move (0.5,-0.5);
	t2->scale (0.2);
	t2->rotate (-50);
    rectangle_add (t2);

    while (!shouldClose()) {
        render ();
		sgl_set_clear_color ({(float)glm::sin(glfwGetTime()),
                              (float)glm::sin(glfwGetTime()-4),
                              (float)glm::sin(glfwGetTime()-8)});
        t2->rotate (5);
    }
    destruct_SGL ();

}
