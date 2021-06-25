#include "Snake.h"

Snake::Snake() {
    move_speed = 1;
    len = 2;
    direction = RIGHT;
    head_pos.set_next(tail_pos);
}

void Snake::grow() {
    len++;
    return;
}

Coordinate Snake::get_headpos() {
    return head_pos;
}

Coordinate Snake::get_tailpos() {
    return tail_pos;
}

void Snake::mode_head(DIRECTION direction) {
    Coordinate temp_pos = head_pos;
    switch (direction) {
        case UP:
            head_pos.set_x(head_pos.get_x() + move_speed);
            break;
        case DOWN:
            head_pos.set_x(head_pos.get_x() - move_speed);
            break;
        case LEFT:
            head_pos.set_y(head_pos.get_y() - move_speed);
            break;
        case RIGHT:
            head_pos.set_y(head_pos.get_y() + move_speed);
            break;
    }
    head_pos.set_next(temp_pos);
    return;
}

void Snake::move_tail() {
    Coordinate temp_pos = *head_pos.get_next();
    while (temp_pos.get_next() != &tail_pos) {
        temp_pos = *temp_pos.get_next();
    }
    tail_pos = temp_pos;
    tail_pos.set_next_nullptr();
    return;
}