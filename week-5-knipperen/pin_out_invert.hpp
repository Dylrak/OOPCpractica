#ifndef pin_out_INVERT_HPP
#define pin_out_INVERT_HPP

#include "hwlib.hpp"

class pin_out_invert : public hwlib::pin_out {
private:
	hwlib::pin_out * slave;
public:
	pin_out_invert( auto & slave):
		slave ( &slave)
	{}
	void set(
		bool x,
		hwlib::buffering buf = hwlib::buffering::unbuffered
	) override {
		slave->set(!x);
	}
};

#endif // pin_out_INVERT_HPP
