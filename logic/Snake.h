#ifndef SNAKE_H
#define SNAKE_H

#include <logic/Coordinate.h>

class Snake {
private:
    Coordinate head_pos = Coordinate(15, 15); // start position is middle of board
    Coordinate tail_pos = Coordinate(14, 15);

    DIRECTION direction;
    int move_speed;
    int len;

public:
    Snake();

    void grow();

    void mode_head(DIRECTION dir);

    void move_tail();

    Coordinate get_headpos();

    Coordinate get_tailpos();
};

#endif // SNAKE_H
