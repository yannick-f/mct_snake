#include <logic/Board.h>
#include "msp.h"

int main(void)
{
    Board board = Board();
    while(!board.gameover) {
        board.make_move(DOWN);
        board.draw_board();
    }
    int score = board.get_score();

    return 0;
}
