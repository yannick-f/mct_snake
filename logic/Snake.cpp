#include <logic/Snake.h>

Snake::Snake() {
	move_speed = 1;
	len = 2;
	direction = RIGHT;
	head_pos.set_next(tail_pos);
}

void Snake::grow() {
	len++;
	return;
}

Coordinate Snake::get_headpos() {
	return head_pos;
}

Coordinate Snake::get_tailpos() {
	return tail_pos;
}

void Snake::move_head(DIRECTION dir) {
	Coordinate temp_pos = head_pos;

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
	head_pos.set_next(temp_pos);
	return;
}

void Snake::move_tail() {
	Coordinate temp_pos = *head_pos.get_next();
	while (temp_pos.get_next() != &tail_pos) {
		temp_pos = *temp_pos.get_next();
	}
	tail_pos = temp_pos;
	tail_pos.set_next_nullptr();
	return;
}
