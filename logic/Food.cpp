#include "Food.h"
#include <cstdlib>

// generate a new random food Coordinate on the board
void Food::generate_new_food() {
	pos.set_x((rand() % x_max - 3) + 1);
	pos.set_y((rand() % y_max - 3) + 1);
	return;
}

// getter
Coordinate Food::get_position() {
	return pos;
}
