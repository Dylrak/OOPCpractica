#ifndef WALL_HPP
#define WALL_HPP

#include "rectangle.hpp"

class wall : public rectangle {
private:
	bool filled;
	int wall_width;
	int update_interval, update_count = 1;
public:
	wall( window & w, const vector & start, const vector & end, const int & update_interval = 200, const bool & filled = true);
	void draw() override;
	void update() override;
};

#endif // WALL_HPP
