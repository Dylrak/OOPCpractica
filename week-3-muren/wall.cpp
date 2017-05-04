#include "wall.hpp"

wall::wall( window & w, const vector & start, const vector & end, const int & update_interval, const bool & filled):
	rectangle(w, start, end),
	filled ( filled ),
	update_interval ( update_interval )
	{
	}

void wall::draw() {
	rectangle::draw();
	vector diff = rectangle::size - rectangle::location;
	if (filled) {
		vector identity (1, 1);
		if (diff.x < diff.y) {
			wall_width = diff.x;
		} else {
			wall_width = diff.y;
		}
		for (int i = 1; i < wall_width; i++) {
			rectangle filler (w, rectangle::location + identity * i, rectangle::size - identity * i);
			filler.draw();
		}
	}
}