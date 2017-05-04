#ifndef FILLED_RECTANGLE_H
#define FILLED_RECTANGLE_H

#include "window.hpp"
#include "vector.hpp"

class filled_rectangle {
private:
	//position of upper left corner
	int start_x;
	int start_y;
	//position of lower right corner
	int end_x;
	int end_y;
	window & w;
public:
	filled_rectangle(window & w, const vector & start, const vector & end ):
	start_x( start.x ),
	start_y( start.y ),
	end_x( end.x ),
	end_y( end.y ),
	w( w )
	{}
	void print();
};

#endif // FILLED_RECTANGLE_H
