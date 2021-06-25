#ifndef MCT_SNAKE_BOARD_H
#define MCT_SNAKE_BOARD_H

#include <logic/Coordinate.h>
#include <logic/Food.h>
#include <logic/Snake.h>

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

    void draw_board();
};

#endif //MCT_SNAKE_BOARD_H
