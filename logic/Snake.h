#ifndef SNAKE_H
#define SNAKE_H

#include <logic/Coordinate.h>
#include <logic/enums.h>

class Snake {
private:
    Coordinate head_pos = Coordinate(15, 15); // start position is middle of board
    Coordinate tail_pos = Coordinate(14, 15);

    DIRECTION direction;
    int move_speed;

public:
    Snake();

    void grow();

    void move_head(DIRECTION dir);

    void move_tail(Coordinate coord);

    Coordinate get_headpos();

    Coordinate get_tailpos();
};

#endif // SNAKE_H
