/// @file

#ifndef MPU6050_HPP
#define MPU6050_HPP
namespace hwlib {

#define MPU_ADDR 0x68

/// \brief
/// library for mpu6050
/// \details
/// TODO
/// Limitations:
///		-the speed is fixed at ~500kHz, or somewhat lower
class mpu6050 : public i2c_bus {
private:
	pin_oc & scl, & sda;
	void wait_half_period(){
		wait_us( 5 );
	}
	void write_bit( bool x ){
		scl.set( 0 );
		wait_half_period();
		sda.set( x );
		scl.set( 1 );
		wait_half_period();
	}

	bool read_bit(){
		scl.set( 0 );
		sda.set( 1 );
		wait_half_period();
		scl.set( 1 );
		wait_half_period();
		bool result = sda.get();
		wait_half_period();
		return result;
	}
	void write_start(){
		sda.set( 0 );
		wait_half_period();
		scl.set( 0 );
		wait_half_period(); 
	}

	void write_stop(){
		scl.set( 0 );
		wait_half_period();
		sda.set( 0 );
		wait_half_period();
		scl.set( 1 );
		wait_half_period();
		sda.set( 1 );
		wait_half_period();
	}
	 
	bool read_ack(){
		bool ack = ! read_bit(); 
		return ack;
	} 

	void write_ack(){
		write_bit( 0 );
	}

	void write_nack(){
		write_bit( 1 );
	}

	void write_byte( uint_fast8_t x ){
		for( uint_fast8_t i = 0; i < 8; i++ ){
			write_bit( ( x & 0x80 ) != 0 );
			x = x << 1;
		}
	 }

	uint_fast8_t read_byte(){
		uint_fast8_t result = 0;
		for( uint_fast8_t i = 0; i < 8; i++ ){
			result = result << 1;
			if( read_bit() ){
				result |= 0x01;
			} 
		}	
		return result;
	}
public:
	/// \brief
	/// construct a bit-banged I2C bus from the scl and sda pins, specialized for the MPU 6050
	/// \details
	/// This constructor creates a bit-banged I2C bus master
	/// from the scl and sda pins, specialized for the MPU 6050.
	mpu6050 ( pin_oc & scl, pin_oc & sda ):
		scl( scl ), sda( sda )
	{
		scl.set( 1 );
		sda.set( 1 );
	}
	/// \brief
	/// write to the MPU 6050
	/// \details
	/// This function writes n bytes of data to the MPU 6050 with address a.
	void write( 
		uint_fast8_t a,
		const uint8_t data[],
		size_t n 
	) override {
		write_start();
		write_byte( MPU_ADDR << 1 );
		read_ack();
		write_byte( a );
		for( size_t i = 0; i < n; i++ ){
			read_ack();
			write_byte( data[ i ] );
		}
		read_ack();
		write_stop();
	}
	
	/// \brief
	/// read from the MPU 6050
	/// \details
	/// This function reads n bytes of data from the MPU 6050 with address a.
	void read( 
		uint_fast8_t a,
		uint8_t data[],
		size_t n
	) override {
		write_start();
		write_byte( MPU_ADDR << 1 );
		read_ack();
		write_byte( a );
		read_ack();
		write_start();
		write_byte( ( MPU_ADDR << 1 ) | 0x01 );
		read_ack();
		for( uint_fast8_t i = 0; i < n; i++ ){
			if( i > 0 ){
				write_ack();
			}
			data[ i ] = read_byte();
		}
		write_stop();
	}
	/// \brief
	/// Initialise the MPU 6050
	/// \details
	/// This function initialises the MPU 6050 by turning of the 'sleep' bit, located at address 0x6B
	void init() {
		write(0x6B, 0x00, 1);
	}
};

} //namespace hwlib
#endif // MPU6050_HPP
