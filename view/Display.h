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
	void draw(uGUI gui, int x, int y, int status);

public:
	void clear(uGUI gui);

	void setStartDisplay(uGUI gui);

	void update_playdisplay(uGUI gui, int *board);

	void show_score(uGUI gui, int score);
};

#endif //MCT_SNAKE_BOARDDISPLAY_H
