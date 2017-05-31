#ifndef WAGON_HPP
#define WAGON_HPP

#include "circle.hpp"
#include "window.hpp"
#include "filled_rectangle.hpp"
#include "line.hpp"

class wagon
{
private:
	int start_x, start_y, end_x, end_y, cabin_width;

	filled_rectangle cabin;
	circle left_wheel;
	circle right_wheel;
	line connector;
	bool has_connector;

	window & w;
public:
	wagon(window & w, int cabin_left, int cabin_start, int cabin_right, int cabin_end, line connector, bool has_connector):
	start_x ( cabin_left ),
	start_y ( cabin_start ),
	end_x ( cabin_right ),
	end_y ( cabin_end ),
	cabin_width ( end_x - start_x ),
	cabin (filled_rectangle(w, start_x, start_y, end_x, end_y)),
	left_wheel (circle(w, start_x + cabin_width / 4, end_y, cabin_width / 4)),
	right_wheel (circle(w, start_x + cabin_width * 3 / 4, end_y, cabin_width / 4)),
	connector ( connector ),
	w ( w )
	{}
	void print();
};

#endif // WAGON_HPP
