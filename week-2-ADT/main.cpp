#include "ostream"
#include "vector.hpp"

// needed to get Catch working with MinGW
#define TWOBLUECUBES_CATCH_REPORTER_JUNIT_HPP_INCLUDED
namespace Catch{ class JunitReporter{ ~JunitReporter(); }; };

#include "catch_with_main.hpp"

TEST_CASE( "constructor, two_parameters" ){
   vector v( 3, 4 );
   std::stringstream s;
   s << v;
   REQUIRE( s.str() == "(3, 4)" );   
}
TEST_CASE( "equality, equal" ){
	vector v( 1, 2 );
	REQUIRE( v == vector( 1, 2 ) ); 
}
TEST_CASE( "equality, unequal" ){
   vector v( 1, 2 );
   REQUIRE( ! ( v == vector( 1, 3 )) ); 
}
TEST_CASE( "add vector to vector using +" ){
	vector v(1, 2);
	vector x(2, 4);
	REQUIRE( v + x == vector( 3, 6 ) ); 
}
TEST_CASE( "add vector to vector using +=" ){
	vector v(1, 2);
	v += vector(2, 4);
	REQUIRE( v == vector( 3, 6 ) ); 
}
TEST_CASE( "multiply vector by integer using *=" ){
	vector v(1, 2);
	v *= 3;
	REQUIRE( v == vector( 3, 6 ) ); 
}
TEST_CASE( "multiply vector by integer using *" ){
	vector v(1, 2);
	REQUIRE( v * 3 == vector( 3, 6 ) ); 
}
TEST_CASE( "multiply integer by vector using *" ){
	vector v(1, 2);
	REQUIRE( 3 * v == vector( 3, 6 ) ); 
}