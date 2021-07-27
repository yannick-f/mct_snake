//
// Created by freischlad on 02.07.2021.
//

#ifndef MCT_SNAKE_BOARDDISPLAY_H
#define MCT_SNAKE_BOARDDISPLAY_H

#include <cstdlib>
#include "st7735s_drv.h"
#include "uGUI.h"
#include <logic/enums.h>

class Display {
private:
	int pos = 0;
	int difficulty = 0;
	static void windowstart_callback(uGUI::MESSAGE* msg);

public:
	uGUI init();

	void setStartDisplay(uGUI gui);

	void setPlayDisplay();

	void change_pos(DIRECTION dir);

	int get_pos();

	int get_difficulty();
};

#endif //MCT_SNAKE_BOARDDISPLAY_H
