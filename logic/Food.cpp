#include "Food.h"
#include <cstdlib>

void Food::generate_new_food() {
    pos.set_x((rand() % x_max - 3) + 1);
    pos.set_y((rand() % y_max - 3) + 1);
    return;
}

Coordinate Food::get_position() {
    return pos;
}
