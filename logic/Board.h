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

    void set_occupied(Coordinate coord, Object object);

    void set_unoccupied(Coordinate coord);

    Snake snake;
    Food food;
    int score;

public:
    Board();

    void make_move(DIRECTION direction);

    bool gameover;

    int get_score();

    Snake get_snake();
};

#endif //MCT_SNAKE_BOARD_H
