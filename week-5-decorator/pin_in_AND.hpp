#ifndef PIN_IN_AND_HPP
#define PIN_IN_AND_HPP
#include "hwlib.hpp"

class pin_in_AND : public hwlib::pin_in {
private:
	hwlib::pin_in & slave0, & slave1;
public:
	pin_in_AND (hwlib::pin_in & slave0, hwlib::pin_in & slave1):
		slave0 (slave0),
		slave1 (slave1)
	{}
	bool get(
		hwlib::buffering buf = hwlib::buffering::unbuffered 
	) override {
		return (!slave0.get() && !slave1.get());
	}
};

#endif // PIN_IN_AND_HPP
