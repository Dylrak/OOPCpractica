#include "filled_rectangle.hpp"

void filled_rectangle::print() {
	w.clear();
	//We use <= so our end variable can be our largest value (if 128x64 then end_y = 64 is possible)
	for (int y = start_y; y <= end_y; y++) {
		for (int x = start_x; x <= end_x; x++) {
			w.draw(x, y);
		}
	}
}
