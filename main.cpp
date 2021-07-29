#include "logic/Board.h"
#include "gpio_msp432.h"
#include "adc14_msp432.h"
#include "view/Display.h"
#include "logic/enums.h"

#include "st7735s_drv.h"
#include "uGUI.h"
#include "spi_msp432.h"
#include <cstdlib>

DIRECTION get_dir(int x_val, int y_val, int x_offset, int y_offset) {
	if (x_val >= y_val) {
		if (x_val - x_offset > 200) {
			return RIGHT;
		} else if (x_val - x_offset < -200) {
			return LEFT;
		}
	} else if (x_val < y_val) {
		if (y_val - y_offset > 200) {
			return UP;
		} else if (y_val - y_offset < -200) {
			return DOWN;
		}
	}
	return REMAINS_SAME;
}

int main(void) {
	// Setup SPI interface
	gpio_msp432_pin lcd_cs(PORT_PIN(5, 0));
	spi_msp432 spi(EUSCI_B0_SPI, lcd_cs);
	spi.setSpeed(24000000);

	// Setup LCD driver
	gpio_msp432_pin lcd_rst(PORT_PIN(5, 7));
	gpio_msp432_pin lcd_dc(PORT_PIN(3, 7));
	st7735s_drv lcd(spi, lcd_rst, lcd_dc, st7735s_drv::Crystalfontz_128x128);

	// Setup uGUI
	uGUI gui(lcd);

	lcd.clearScreen(0x0);

	// initialise button
	gpio_msp432_pin button(PORT_PIN(5, 1));
	button.gpioMode(GPIO::INPUT | GPIO::PULLUP);

	// initialise joystick
	adc14_msp432_channel joy_x(15);
	adc14_msp432_channel joy_y(9);
	joy_x.adcMode(ADC::ADC_10_BIT);
	joy_y.adcMode(ADC::ADC_10_BIT);

	uint16_t offset_x = joy_x.adcReadRaw();
	uint16_t offset_y = joy_y.adcReadRaw();

	// setup menu
	Display display;
//	display.setStartDisplay(gui);
//
//	while (true) {
//		uint16_t read_x = joy_x.adcReadRaw();
//		uint16_t read_y = joy_y.adcReadRaw();
//
//		DIRECTION dir = get_dir(read_x, read_y, offset_x, offset_y);
//		display.change_pos(dir);
//
//		// check if button is pressed
//		if (button.gpioRead()) {
//			if (display.get_pos() == 3) {
//				break;
//			}
//		}
//	}
//
//	int difficulty = display.get_difficulty();

//game
	Board board = Board();
    display.update_playdisplay(gui, board.get_board());
	while (!board.get_gamestatus()) {
		uint16_t read_x = joy_x.adcReadRaw();
		uint16_t read_y = joy_y.adcReadRaw();

		DIRECTION dir = get_dir(read_x, read_y, offset_x, offset_y);

		board.make_move(dir);
        display.update_playdisplay(gui, board.get_board());
	}
	int score = board.get_score();

	return 0;
}
