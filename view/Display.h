//
// Created by freischlad on 02.07.2021.
//

#ifndef MCT_SNAKE_BOARDDISPLAY_H
#define MCT_SNAKE_BOARDDISPLAY_H

#include <cstdlib>
#include "st7735s_drv.h"
#include "uGUI.h"

class Display {
private:
	st7735s_drv lcd;
	uGUI gui;
	static void windowstart_callback(uGUI::MESSAGE* msg);

public:
	void init();

	void setStartDisplay();

	void setPlayDisplay();
};

#endif //MCT_SNAKE_BOARDDISPLAY_H
