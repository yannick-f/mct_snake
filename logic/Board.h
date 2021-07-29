#ifndef MCT_SNAKE_BOARD_H
#define MCT_SNAKE_BOARD_H

#include "Coordinate.h"
#include "Food.h"
#include "Snake.h"

enum Object {
    FOOD, SNAKE
};

class Board {
private:
    int board[32][32] = {0};

    int get_status(Coordinate coord);

    bool collision(Coordinate coord);

    void set_occupied(Coordinate coord, int object);

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

    int *get_board();
};

#endif //MCT_SNAKE_BOARD_H
