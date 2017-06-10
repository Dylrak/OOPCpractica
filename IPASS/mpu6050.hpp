/// @file

#ifndef MPU6050_BIT_BANGED_HPP
#define MPU6050_BIT_BANGED_HPP
#define MPU_ADDR 0x68
namespace hwlib {

/// \brief
/// bit-banged i2c bus implementation for mpu6050
/// \details
/// TODO
/// Limitations:
///		-the speed is fixed at ~400kHz, or somewhat higher
class mpu6050_bit_banged : public i2c_bus
{
private:
	pin_oc & scl, & sda;
	//Most of these private functions are a direct copy of the other bit bang method,
	//but we shall use them differently in the pubic space of this class.
	void wait_half_period(){
		wait_us( 1 );
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
public:
	mpu6050_bit_banged();
};

}
#endif // MPU6050_BIT_BANGED_HPP
