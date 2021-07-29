#ifndef MCT_SNAKE_BOARD_H
#define MCT_SNAKE_BOARD_H

#include "Coordinate.h"
#include "Food.h"
#include "Snake.h"

class Board {
private:
	int board[32][32] = { 0 };

	int get_status(Coordinate coord);
	int get_status(int x, int y);

	bool collision(Coordinate coord);

	void set_occupied(Coordinate coord, int object);
	int counter;

	void set_unoccupied(Coordinate coord);

	Snake snake;
	Food food;

	int score;
	bool gameover;

public:
	Board();

	void make_move(DIRECTION direction);

	bool get_gamestatus();

	int get_score();

	Snake get_snake();

	int* get_board();

	Coordinate get_lowest_adjacent(Coordinate coord);
};

#endif //MCT_SNAKE_BOARD_H
