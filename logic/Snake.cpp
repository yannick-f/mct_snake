#include <logic/Snake.h>

Snake::Snake() {
	move_speed = 1;
	direction = RIGHT;
}

Coordinate Snake::get_headpos() {
	return head_pos;
}

Coordinate Snake::get_tailpos() {
	return tail_pos;
}

/**
 * moves the head in the given direction
 */
void Snake::move_head(DIRECTION dir) {
	// if dir is REMAINS_SAME the snake just keeps moving in the same direction
	if (dir == REMAINS_SAME) {
		dir = this->direction;
	}

	switch (dir) {
	case UP:
		head_pos.set_y(head_pos.get_y() + move_speed);
		break;
	case DOWN:
		head_pos.set_y(head_pos.get_y() - move_speed);
		break;
	case LEFT:
		head_pos.set_x(head_pos.get_x() - move_speed);
		break;
	case RIGHT:
		head_pos.set_x(head_pos.get_x() + move_speed);
		break;
	}
	this->direction = dir;
	return;
}

/**
 * moves the tail to the given Coordinate
 */
void Snake::move_tail(Coordinate coord) {
	tail_pos = coord;
	return;
}
