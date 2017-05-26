#include "hwlib.hpp"

void skitt (auto leds, int wait_time) {
	for (;;) {
		for (unsigned int i = 0; i < leds.number_of_pins() - 1; i++) {
			leds.set(0x03 << i);
			hwlib::wait_ms(wait_time);
		}
		//Skip the 'last' LED and start from 1 behind (Because we bitshift 0x03). 
		for (unsigned int i = leds.number_of_pins() - 3; i > 0; i--) {
			leds.set(0x03 << i);
			hwlib::wait_ms(wait_time);
		}
	}
}


int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
	//initialise LEDs
	namespace target = hwlib::target;
	auto led0 = target::pin_out (target::pins::d2);
	auto led1 = target::pin_out (target::pins::d3);
	auto led2 = target::pin_out (target::pins::d4);
	auto led3 = target::pin_out (target::pins::d5);
	//Concatenate LEDS into one variable
	auto leds = hwlib::port_out_from_pins (led0, led1, led2, led3);
	
	skitt (leds, 500);
}
