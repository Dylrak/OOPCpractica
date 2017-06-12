#include "hwlib.hpp"
#include "mpu6050.hpp"


int main( void ){
	WDT->WDT_MR = WDT_MR_WDDIS;

	namespace target = hwlib::target;

	auto scl = target::pin_oc( target::pins::scl );
	auto sda = target::pin_oc( target::pins::sda );

	auto mpu_scl = target::pin_oc( target::pins::a5 );
	auto mpu_sda = target::pin_oc( target::pins::a4 );

	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
	auto mpu_6050 = hwlib::mpu6050( mpu_scl, mpu_sda );
	auto display = hwlib::glcd_oled( i2c_bus, 0x3c );

	//Player is an image_8x8 test containing alternating stripes.
	auto player = hwlib::image_8x8 (0, ~0, 0, ~0, 0, ~0, 0, ~0);
	//Dummy is an image8x8 test containing only empty slots. it will be used to overwrite player.
	auto dummy = hwlib::image_8x8 (0, 0, 0, 0, 0, 0, 0, 0);

	uint8_t gyro_data[1];

	mpu_6050.init();

	for (;;) {
		mpu_6050.read(0x43, gyro_data, 1);
		gyro_data[0] = gyro_data[0] % 64;

		display.clear();
		display.write(hwlib::location(gyro_data[0], 10), player, hwlib::buffering::unbuffered);
	}

//	// We subtract the size of a uint8_t from the maximum X-value in order to not draw images outside of screen.
//	for (uint8_t x = 0; x < display.size.x - sizeof(uint8_t); x++) {
//		display.write( hwlib::location( x, 10 ), player, hwlib::buffering::buffered);
//		display.write( hwlib::location( x, 10 ), dummy, hwlib::buffering::buffered);
//		display.flush();
//	}
}