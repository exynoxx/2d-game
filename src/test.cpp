#include <sGL.h>

extern std::vector<sgl_triangle> objs;

int main (){

	init_SGL ();
    sgl_triangle t;
    objs.push_back (t);

    while (1) {
        render ();
    }
    destruct_SGL ();

}
