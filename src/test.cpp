#include <sGL.h>

int main (){

	init_SGL ();
    sgl_triangle t = create_triangle ();

    while (1) {
        render ();
    }
    destruct_SGL ();

}
