//
// Created by freischlad on 02.07.2021.
//

#include "Display.h"
#include "gpio_msp432.h"
#include "uGUI_colors.h"
#include "font_8x8.h"
#include "font_22x36.h"
#include "font_32x53.h"
#include "logic/Coordinate.h"
#include "yahal_String.h"
#include "task.h"

void Display::clear(uGUI gui) {
	gui.FillScreen(C_BLACK);
}

void Display::setStartDisplay(uGUI gui) {
	// blackscreen
	gui.FillScreen(C_BLACK);

	UG_COLOR color = C_ORANGE_RED;

	gui.SetForecolor(color);
	gui.FontSelect(&FONT_22X36);
	gui.PutString(8, 0, "SNAKE", true);

	gui.SetForecolor(color);
	gui.FontSelect(&FONT_8X8);
	gui.PutString(10, 50, "Press Button", true);
	gui.PutString(30, 60, "to Start", true);

	// draw the A in a circle
	gui.DrawCircle(64, 100, 20, color);
	gui.SetForecolor(color);
	gui.FontSelect(&FONT_22X36);
	gui.PutString(53, 82, "A", true);
	return;
}

void Display::update_playdisplay(uGUI gui, int *board) {
	int size = 32;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			int res = *(board + (i * size) + j);
			// if occupied -> draw
			if (res != 0) {
				draw(gui, i, j, res);
				if (res == -1) {
					*(board + (i * size) + j) = 0;
				}
			}
		}
	}
	return;
}

void Display::show_score(uGUI gui, int score) {
	gui.FillScreen(C_BLACK);

	gui.SetForecolor(C_YELLOW);
	gui.FontSelect(&FONT_8X8);
	gui.PutString(5, 15, "Your Score is", true);

	gui.SetForecolor(C_YELLOW);
	gui.FontSelect(&FONT_32X53);
	gui.PutString(45, 40, to_String(score), true);

	gui.SetForecolor(C_YELLOW);
	gui.FontSelect(&FONT_8X8);
	gui.PutString(5, 100, "Press  Button", true);
	gui.PutString(5, 110, "To Play Again", true);

	task::sleep(5000);
}

void Display::draw(uGUI gui, int x, int y, int status) {
	// convert from32x32 to 128x128
	x = x * 4;
	y = y * 4;

	if (status == -1) {
		gui.FillFrame(x, y, x + 4, y + 4, C_BLACK);
	} else if (status == 1) {
		gui.FillCircle(x + 2, y + 2, 2, C_RED);
	} else {
		gui.FillFrame(x, y, x + 4, y + 4, C_YELLOW);
	}
	return;
}
