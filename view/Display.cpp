//
// Created by freischlad on 02.07.2021.
//

#include "Display.h"
#include "gpio_msp432.h"
#include "uGUI_colors.h"
#include "font_7x12.h"
#include "font_32x53.h"
#include "logic/Coordinate.h"
#include "yahal_String.h"

void Display::windowstart_callback(uGUI::MESSAGE *msg) {
	return;
}

void Display::setStartDisplay(uGUI gui) {
	// blackscreen
	gui.FillScreen(C_BLACK);

	uGUI::WINDOW window;
	uGUI::BUTTON buttonEasy;
	uGUI::BUTTON buttonMedium;
	uGUI::BUTTON buttonHard;
	uGUI::BUTTON buttonStart;
	uGUI::TEXTBOX textbox;
	uGUI::OBJECT obj_buff_wnd_1[10];

	// ids
	uint8_t button_easy_id = 0x0000;
	uint8_t button_medium_id = 0x0001;
	uint8_t button_hard_id = 0x0002;
	uint8_t button_start_id = 0x0003;
	uint8_t textbox_id = 0x0004;

	// setup window
	gui.WindowCreate(&window, obj_buff_wnd_1, 10, windowstart_callback);
	gui.WindowSetTitleText(&window, "Snake - MCT Version");
	gui.WindowSetTitleTextFont(&window, &FONT_7X12);

	// setup button
	gui.ButtonCreate(&window, &buttonEasy, button_easy_id, 5, 20, 15, 40);
	gui.ButtonCreate(&window, &buttonMedium, button_medium_id, 50, 20, 60, 40);
	gui.ButtonCreate(&window, &buttonHard, button_hard_id, 95, 20, 105, 40);
	gui.ButtonCreate(&window, &buttonStart, button_start_id, 40, 80, 80, 100);

	gui.ButtonSetFont(&window, button_easy_id, &FONT_7X12);
	gui.ButtonSetFont(&window, button_medium_id, &FONT_7X12);
	gui.ButtonSetFont(&window, button_hard_id, &FONT_7X12);
	gui.ButtonSetFont(&window, button_start_id, &FONT_7X12);

	gui.ButtonSetText(&window, button_easy_id, "Easy");
	gui.ButtonSetText(&window, button_medium_id, "Medium");
	gui.ButtonSetText(&window, button_hard_id, "Hard");
	gui.ButtonSetText(&window, button_start_id, "Start Game");

	// setup textbox
	gui.TextboxCreate(&window, &textbox, textbox_id, 10, 100, 100, 120);
	gui.TextboxSetFont(&window, textbox_id, &FONT_7X12);
	char *msg = "This is an example text";
	gui.TextboxSetText(&window, textbox_id, msg);

	// show window
	gui.WindowShow(&window);
	return;
}

void Display::update_playdisplay(uGUI gui, int *board) {
	gui.FillScreen(C_BLACK);

	int size = 32;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			int res = *(board + (i * size) + j);
			if (res != 0) {
				draw(gui, i, j);
			}
		}
	}
	return;
}

void Display::show_score(uGUI gui, int score) {
	gui.FillScreen(C_BLACK);
	gui.PutString(15, 15, to_String(score), true);
}

void Display::draw(uGUI gui, int x, int y) {
	// umrechnen von 32x32 zu 128x128
	x = x * 4;
	y = y * 4;

	gui.FillFrame(x, y, x + 4, y + 4, C_YELLOW);
	return;
}

void Display::change_pos(DIRECTION dir) {
	switch (dir) {
	case REMAINS_SAME:
		return;
	case UP:
		if (pos == 0 || pos == 1 || pos == 2) {
			pos = 3;
		} else if (pos == 3) {
			pos = 2;
		}
		break;
	case DOWN:
		if (pos == 0 || pos == 1 || pos == 2) {
			pos = 3;
		} else if (pos == 3) {
			pos = 0;
		}
		break;
	case LEFT:
		if (pos == 0) {
			pos = 3;
			break;
		}
		pos -= 1;
		break;
	case RIGHT:
		if (pos == 3) {
			pos = 0;
			break;
		}
		pos += 1;
		break;
	}

	// set difficulty
	if (pos != 3) {
		difficulty = pos;
	}
	return;
}

int Display::get_pos() {
	return pos;
}

int Display::get_difficulty() {
	return difficulty;
}
