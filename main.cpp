#include "msp.h"
#include "./game/Board.h"

int main(void)
{
    Board board = Board();
    while(!board.gameover) {
        std::cout << i;
        board.make_move(DOWN);
        board.draw_board();
    }
    int score = board.get_score();

    return 0;
}
