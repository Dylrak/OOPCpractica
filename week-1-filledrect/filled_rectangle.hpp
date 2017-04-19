#ifndef FILLED_RECTANGLE_H
#define FILLED_RECTANGLE_H

#include "window.hpp"

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
	filled_rectangle(window & w, int start_x, int start_y, int end_x, int end_y ):
	start_x( start_x ),
	start_y( start_y ),
	end_x( end_x ),
	end_y( end_y ),
	w( w )
	{}
	void print();
};

#endif // FILLED_RECTANGLE_H
