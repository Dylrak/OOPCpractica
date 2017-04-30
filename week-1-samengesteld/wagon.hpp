#ifndef WAGON_HPP
#define WAGON_HPP

#include "circle.hpp"
#include "window.hpp"
#include "filled_rectangle.hpp"

class wagon
{
private:
	int start_x, start_y, end_x, end_y, cabin_width;
	window & w;
public:
	wagon(window & w, int cabin_left, int cabin_start, int cabin_right, int cabin_end):
	start_x ( cabin_left ),
	start_y ( cabin_start ),
	end_x ( cabin_right ),
	end_y ( cabin_end ),
	cabin_width ( end_x - start_x ),
	w ( w )
	{}
	void print();
};

#endif // WAGON_HPP
