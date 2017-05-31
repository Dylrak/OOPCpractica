#include "pin_in_AND.hpp"

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;

	namespace target = hwlib::target;

	auto button0 = target::pin_in( target::pins::d11 );
	auto button1 = target::pin_in( target::pins::d12 );
	auto led0 = target::pin_out( target::pins::d2 );
	
	auto AND = pin_in_AND (button0, button1);
	for (;;) {
		led0.set(AND.get());
	}
}