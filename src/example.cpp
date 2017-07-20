#include <sGL.h>

sgl_shape *t1;
sgl_shape *t2;

float dist = 0.3;

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

    sgl_shape *a = sgl_create_square_color (0x00FFAA);
    sgl_shape *b = sgl_create_triangle_texture ("res/tree.jpg");

    a->move (-0.5, 0.5);
    b->move (0.5, -0.5);

    while (!shouldClose()) {
        render ();
		sgl_set_clear_color ({(float)glm::sin(glfwGetTime()),
                              (float)glm::sin(glfwGetTime()-4),
                              (float)glm::sin(glfwGetTime()-8)});
    }
    destruct_SGL ();

}
