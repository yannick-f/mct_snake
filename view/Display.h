//
// Created by freischlad on 02.07.2021.
//

#ifndef MCT_SNAKE_BOARDDISPLAY_H
#define MCT_SNAKE_BOARDDISPLAY_H

#include <cstdlib>
#include "uGUI.h"
#include <logic/enums.h>
#include "logic/Snake.h"

class Display {
private:
	int pos = 0;
	int difficulty = 0;
	void draw(uGUI gui, int x, int y);

	static void windowstart_callback(uGUI::MESSAGE *msg);

public:
	void setStartDisplay(uGUI gui);

	void update_playdisplay(uGUI gui, int *board);

	void show_score(uGUI gui, int score);

	void change_pos(DIRECTION dir);

	int get_pos();

	int get_difficulty();
};

#endif //MCT_SNAKE_BOARDDISPLAY_H
