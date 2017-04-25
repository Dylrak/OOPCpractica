#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "window.hpp"

class circle
{
private:
	int x0;
	int y0;
	int radius;
	window & w;
public:
	circle(window & w, int x_pos, int y_pos, int radius):
	x0( x_pos ),
	y0( y_pos ),
	radius( radius ),
	w( w )
	{}
	void print();
};

#endif // CIRCLE_HPP
