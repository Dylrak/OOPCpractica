#ifndef VICTIM_HPP
#define VICTIM_HPP

#include "rectangle.hpp"

class victim : public rectangle {
private:
	bool dying;
public:
	victim(window & w, const vector & start, const vector & end, const bool & dying = false);
	void interact(drawable & other) override;
	void update() override;
};

#endif // VICTIM_HPP
