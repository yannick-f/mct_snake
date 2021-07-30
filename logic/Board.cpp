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

/**
 * get the status of a Coordinate on the board
 * -> 0 unoccupied
 * -> 1 Food
 * -> 2-n Snake-body
 */
int Board::get_status(Coordinate coord) {
	return board[coord.get_x()][coord.get_y()];
}

/**
 * get the status of a Coordinate on the board
 * -> 0 unoccupied
 * -> 1 Food
 * -> 2-n Snake-body
 */
int Board::get_status(int x, int y) {
	return board[x][y];
}

/**
 * detects if there is a collision on the given coordinate or if it is out of bounds
 */
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

/**
 * sets a coordinate on the board as occupied
 * -> object give the value to set (1 for Food, 2-n for Snake)
 */
void Board::set_occupied(Coordinate coord, int object) {
	board[coord.get_x()][coord.get_y()] = object;
	return;
}

/**
 * sets a coordinate on the board back to 0/unoccupied
 */
void Board::set_unoccupied(Coordinate coord) {
	board[coord.get_x()][coord.get_y()] = 0;
	return;
}

/**
 * give back the score
 */
int Board::get_score() {
	return score;
}

/**
 * give back the gamestatus:
 * -> true for gameover
 * -> false for still running
 */
bool Board::get_gamestatus() {
	return gameover;
}

/**
 * gives back a pointer to the board
 */
int* Board::get_board() {
	return reinterpret_cast<int*>(board);
}

/**
 * gives the coordinate of the lowest adjacent Coordinate (excl. 0 & 1)
 * is used to find the next tail of the snake
 */
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
