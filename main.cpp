#include "logic/Board.h"
#include "gpio_msp432.h"
#include "adc14_msp432.h"

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
	return RIGHT;
}

int main(void) {
	// initialise joystick
	adc14_msp432_channel joy_x(15);
	adc14_msp432_channel joy_y(9);
	joy_x.adcMode(ADC::ADC_10_BIT);
	joy_y.adcMode(ADC::ADC_10_BIT);

	uint16_t offset_x = joy_x.adcReadRaw();
	uint16_t offset_y = joy_y.adcReadRaw();

	Board board = Board();
	while (!board.gameover) {
		uint16_t read_x = joy_x.adcReadRaw();
		uint16_t read_y = joy_y.adcReadRaw();

		DIRECTION dir = get_dir(read_x, read_y, offset_x, offset_y);

		board.make_move(dir);
		board.draw_board();
	}
	int score = board.get_score();

	return 0;
}
