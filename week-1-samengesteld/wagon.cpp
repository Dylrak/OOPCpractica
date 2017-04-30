#include "wagon.hpp"

void wagon::print()
{
	filled_rectangle cabin (w, start_x, start_y, end_x, end_y);
	circle left_wheel (w, start_x + cabin_width / 4, end_y, cabin_width / 4);
	circle right_wheel (w, start_x + cabin_width * 3 / 4, end_y, cabin_width / 4);
	cabin.print();
	left_wheel.print();
	right_wheel.print();
}
