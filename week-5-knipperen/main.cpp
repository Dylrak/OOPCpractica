#include "pin_out_all.hpp"
#include "pin_out_invert.hpp"

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

//This way works without a pin_out_invert class so I don't know if it is valid.
//	auto left_leds = pin_out_all(
//		led0,
//		led1,
//		led2,
//		led3
//	);
//	auto right_leds = pin_out_all( 
//		hc595.p0,
//		hc595.p1,
//		hc595.p2,
//		hc595.p3
//	);
//
//	auto leds = hwlib::port_out_from_pins(
//		left_leds, right_leds
//	);
//	hwlib::kitt(leds, 200);

// The following code works with blink instead of kitt, but it uses the invert class.
	auto direct_leds = pin_out_all(
		led0,
		led1,
		led2,
		led3
	);
	auto left_leds = pin_out_invert(direct_leds);
	auto leds = pin_out_all( 
		left_leds,
		hc595.p0,
		hc595.p1,
		hc595.p2,
		hc595.p3
	);
	
	hwlib::blink(leds);

}