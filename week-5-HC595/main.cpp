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

	namespace target = hwlib::target;

	auto ds   = target::pin_out( target::pins::d8 );
	auto shcp = target::pin_out( target::pins::d9 );
	auto stcp = target::pin_out( target::pins::d10 );
	auto spi  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
		shcp, ds, hwlib::pin_in_dummy 
	);

	auto hc595 = hwlib::hc595( spi, stcp );

	auto led0 = target::pin_out( target::pins::d2 );
	auto led1 = target::pin_out( target::pins::d3 );
	auto led2 = target::pin_out( target::pins::d4 );
	auto led3 = target::pin_out( target::pins::d5 );

	auto left_leds = hwlib::port_out_from_pins( 
		led0,
		led1,
		led2,
		led3,
		hc595.p0,
		hc595.p1,
		hc595.p2,
		hc595.p3
	);
	::skitt(leds, 200);

}
