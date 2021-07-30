#include "Coordinate.h"

Coordinate::Coordinate(int x_pos, int y_pos) {
	this->x = x_pos;
	this->y = y_pos;
}

Coordinate::Coordinate(const Coordinate &coord) {
	this->x = coord.x;
	this->y = coord.y;
}

int Coordinate::get_x() {
	return x;
}

int Coordinate::get_y() {
	return y;
}

void Coordinate::set_x(int x_pos) {
	this->x = x_pos;
}

void Coordinate::set_y(int y_pos) {
	this->y = y_pos;
}

bool Coordinate::operator==(const Coordinate &rhs) {
	if (this->x == rhs.x && this->y == rhs.y) {
		return true;
	}
	return false;
}

