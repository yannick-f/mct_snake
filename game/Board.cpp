#include "Board.h"
#include <iostream>

Board::Board() {
    snake = Snake();
    food.generate_new_food();
    gameover = false;
}

void Board::make_move(DIRECTION direction) {
    snake.mode_head(direction);
    if (collision(snake.get_headpos())) {
        gameover = true;
        return;
    } else if (snake.get_headpos() == food.get_position()) {
        snake.grow();
        score++;

        food.generate_new_food();
        set_occupied(food.get_position(), FOOD);
    } else {
        snake.move_tail();
    }

    set_occupied(snake.get_headpos(), SNAKE);
    set_unoccupied(snake.get_tailpos());

    return;
}

int Board::get_status(Coordinate coord) {
    return board[coord.get_x()][coord.get_y()];
}

bool Board::collision(Coordinate coord) {
    // // check if snake is outside of bounds
    if (coord.get_x() <= 0 || coord.get_y() <= 0
        || coord.get_x() >= 32 || coord.get_y() >= 32) {
        return true;
    }
    // check if snake has collided with its own body
    if (get_status(coord) == 1) {
        return true;
    }
    return false;
}

void Board::set_occupied(Coordinate coord, Object object) {
    if (object == FOOD) {
        board[coord.get_x()][coord.get_y()] = 2;
    } else if (object == SNAKE) {
        board[coord.get_x()][coord.get_y()] = 1;
    }
    return;
}

void Board::set_unoccupied(Coordinate coord) {
    board[coord.get_x()][coord.get_y()] = 0;
    return;
}

int Board::get_score() {
    return score;
}

void Board::draw_board() {
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            std::cout << board[i][j];
        }
        std::cout << "\n";
    }
}