#ifndef MCT_SNAKE_COORDINATE_H
#define MCT_SNAKE_COORDINATE_H

class Coordinate {
private:
    int x;
    int y;
    Coordinate *next;

public:
    Coordinate(int x_pos, int y_pos);

    Coordinate(const Coordinate &coord);

    int get_x();

    int get_y();

    void set_x(int x_pos);

    void set_y(int y_pos);

    bool operator==(const Coordinate &rhs);
};

#endif //MCT_SNAKE_COORDINATE_H
