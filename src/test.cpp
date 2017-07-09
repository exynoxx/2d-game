#include <sGL.h>

int main (){

	init_SGL ();
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
    }
    destruct_SGL ();

}
