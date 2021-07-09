//
// Created by freischlad on 02.07.2021.
//

#include "Display.h"
#include "gpio_msp432.h"
#include "spi_msp432.h"
#include "st7735s_drv.h"
#include "uGUI.h"
#include "uGUI_colors.h"
#include "font_7x12.h"

void Display::init() {
	// Setup SPI interface
	gpio_msp432_pin lcd_cs(PORT_PIN(5, 0));
	spi_msp432 spi(EUSCI_B0_SPI, lcd_cs);
	spi.setSpeed(24000000);

	// Setup LCD driver
	gpio_msp432_pin lcd_rst(PORT_PIN(5, 7));
	gpio_msp432_pin lcd_dc(PORT_PIN(3, 7));
	lcd(spi, lcd_rst, lcd_dc, st7735s_drv::Crystalfontz_128x128);

	// Setup uGUI
	gui(lcd);

	lcd.clearScreen(0x0);
}

void Display::windowstart_callback(uGUI::MESSAGE* msg) {
	return;
}

void Display::setStartDisplay() {
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
	gui.ButtonCreate(&window, &buttonEasy, button_easy_id, 1, 1, 1, 1);
	gui.ButtonCreate(&window, &buttonMedium, button_medium_id, 1, 1, 1, 1);
	gui.ButtonCreate(&window, &buttonHard, button_hard_id, 1, 1, 1, 1);
	gui.ButtonCreate(&window, &buttonStart, button_start_id, 1, 1, 1, 1);

	gui.ButtonSetFont(&window, button_easy_id, &FONT_7X12);
	gui.ButtonSetFont(&window, button_medium_id, &FONT_7X12);
	gui.ButtonSetFont(&window, button_hard_id, &FONT_7X12);
	gui.ButtonSetFont(&window, button_start_id, &FONT_7X12);

	gui.ButtonSetText(&window, button_easy_id, "Easy");
	gui.ButtonSetText(&window, button_medium_id, "Medium");
	gui.ButtonSetText(&window, button_hard_id, "Hard");
	gui.ButtonSetText(&window, button_start_id, "Start Game");

	// setup textbox
	gui.TextboxCreate(&window, &textbox, textbox_id, 1, 1, 10, 10);
	gui.TextboxSetFont(&window, textbox_id, &FONT_7X12);
	char* msg = "This is an example text";
	gui.TextboxSetText(&window, textbox_id, msg);

	// show window
	gui.WindowShow(&window);
}

void Display::setPlayDisplay() {

}
