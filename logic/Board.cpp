#include "Board.h"

Board::Board() {
	snake = Snake();
	food.generate_new_food();

	score = 0;
	gameover = false;

	// set start positions occupied
	set_occupied(food.get_position(), 1);
	set_occupied(snake.get_tailpos(), 2);
	set_occupied(snake.get_headpos(), 3);

	counter = 4;
}

void Board::make_move(DIRECTION direction) {
	snake.move_head(direction);
	if (collision(snake.get_headpos())) {
		gameover = true;
		return;
	} else if (snake.get_headpos() == food.get_position()) {
		snake.grow();
		score++;
		food.generate_new_food();
		set_occupied(food.get_position(), 1);
	} else {
		int val = get_status(snake.get_tailpos());
		set_unoccupied(snake.get_tailpos());
		snake.move_tail(get_lowest_adjacent(this->snake.get_tailpos(), val));
	}

	set_occupied(snake.get_headpos(), counter);
	counter++;

	return;
}

int Board::get_status(Coordinate coord) {
	return board[coord.get_x()][coord.get_y()];
}

int Board::get_status(int x, int y) {
	return board[x][y];
}

bool Board::collision(Coordinate coord) {
	// // check if snake is outside of bounds
	if (coord.get_x() <= 0 || coord.get_y() <= 0 || coord.get_x() >= 32
			|| coord.get_y() >= 32) {
		return true;
	}
	// check if snake has collided with its own body
	if (get_status(coord) > 1) {
		return true;
	}
	return false;
}

void Board::set_occupied(Coordinate coord, int object) {
	board[coord.get_x()][coord.get_y()] = object;
	return;
}

void Board::set_unoccupied(Coordinate coord) {
	board[coord.get_x()][coord.get_y()] = 0;
	return;
}

int Board::get_score() {
	return score;
}

Snake Board::get_snake() {
	return snake;
}

bool Board::get_gamestatus() {
	return gameover;
}

int* Board::get_board() {
	return reinterpret_cast<int*>(board);
}

Coordinate Board::get_lowest_adjacent(Coordinate coord, int val) {
	int score_w = get_status(coord.get_x() - 1, coord.get_y());
	int score_n = get_status(coord.get_x(), coord.get_y() + 1);
	int score_e = get_status(coord.get_x() + 1, coord.get_y());
	int score_s = get_status(coord.get_x(), coord.get_y() - 1);
	Coordinate res = coord;

	if (score_w == val + 1) {
		res = { coord.get_x() - 1, coord.get_y() };
	} else if (score_n == val + 1) {
		res = { coord.get_x(), coord.get_y() + 1 };
	} else if (score_e == val + 1) {
		res = { coord.get_x() + 1, coord.get_y() };
	} else if (score_s == val + 1) {
		res = { coord.get_x(), coord.get_y() - 1 };
	}
	return res;
}
