#ifndef PIN_OUT_ALL_HPP
#define PIN_OUT_ALL_HPP
#include "hwlib.hpp"

class pin_out_all : public hwlib::pin_out {
private:
   hwlib::pin_out * list[ 8 ];     

public:

	pin_out_all( 
		hwlib::pin_out & p0, 
		hwlib::pin_out & p1 = hwlib::pin_out_dummy,  
		hwlib::pin_out & p2 = hwlib::pin_out_dummy, 
		hwlib::pin_out & p3 = hwlib::pin_out_dummy,  
		hwlib::pin_out & p4 = hwlib::pin_out_dummy,
		hwlib::pin_out & p5 = hwlib::pin_out_dummy,  
		hwlib::pin_out & p6 = hwlib::pin_out_dummy,
		hwlib::pin_out & p7 = hwlib::pin_out_dummy 
	):
		list{ &p0, &p1, &p2, &p3, &p4, &p5, &p6, &p7 }
	{}

	void set( 
		bool v, 
		hwlib::buffering buf = hwlib::buffering::unbuffered 
	){
		for( const auto p : list ){
			p->set( v );
		}
	}
};

#endif // PIN_OUT_ALL_HPP
