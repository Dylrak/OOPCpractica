#include "hwlib.hpp"
#include <cmath>

unsigned int pattern = 0x0;
unsigned int mask = 0xF;
unsigned int counter = 0;
void change_leds (auto leds, auto button_up, auto button_down, int wait_time = 10) {
	for (;;) {
		pattern = mask << (leds.number_of_pins() - counter);
		leds.set(pattern);
		//If increment button is pushed,
		if (!button_up.get() && counter < leds.number_of_pins()) {
			//increment counter,
			counter++;
			hwlib::cout << counter << "\n";
			//and wait until the button is released.
			while (!button_up.get()) {
				hwlib::wait_ms(wait_time); 
			}
		} else if (!button_down.get() && counter > 0) {
			counter--;
			hwlib::cout << counter << "\n";
			while (!button_down.get()) {
				hwlib::wait_ms(wait_time);
			}
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
	//Initialise buttons
	auto button_up = target::pin_in (target::pins::d6);
	auto button_down = target::pin_in (target::pins::d7);
	
	change_leds(leds, button_up, button_down);
}