#include <sGL.h>

extern std::vector<sgl_triangle> objs;
extern bool shouldClose;

int main (){

	init_SGL ();
    sgl_triangle t1;
	t1.move (-0.5, 0.5);
	t1.scale (1.2);
	t1.rotate (90);
    objs.push_back (t1);

	sgl_triangle t2;
	t2.move (0.5,-0.5);
	t2.scale (0.2);
	t2.rotate (-50);
    objs.push_back (t2);


    while (!shouldClose) {
        render ();
    }
    destruct_SGL ();

}
