#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iomanip>
/// @file

/// \brief
/// rational ADT
/// \details
/// This is an ADT that implements rational (fractional) values.
/// The counter and denominator are stored as two (signed) integers.
/// The appropriate constructors and operators are provided.
///
/// Rational values are always simplied (reduced): the counter
/// and denominator have no common factors.
class rational {
private:
   int counter;
   int denominator;
   
   void reduce(){
      int a = counter;
      int b = denominator;

      while( b ){
         int temp = b;
         b = a % b;
         a = temp;
      }

      if( a ){
         counter /= a;
         denominator /= a;
      }
   }
public:
/// \brief
/// constructor from explicit values
/// \details
/// This constructor initializes a rational from its counter and denominator.
/// The default value for the denominator is 1, so a rational can be
/// initialized with just a whole value.
   rational( int counter, int denominator = 1 ):
     counter( counter ), denominator( denominator )
   {}
/// \brief
/// compare two rational values
/// \details
/// This operator tests for equality. It returns true
/// if the reduced counter and denominator of both
/// operands are equal. In order for us to work with reduced variables
/// we copy the values without trying to reduce/change
/// the original constant values.
	bool operator==( const rational & rhs ) const {
		rational left = * this;
		rational right = rhs;
		left.reduce();
		right.reduce();
		return ( left.counter == right.counter ) && ( left.denominator == right.denominator );
	}
/// \brief
/// output operator for a rational value
/// \details
/// This operator<< prints a constructor in the format
/// [counter/denominator] where both values are printed as
/// hexadecimal values, 4 spaces long including a '0x'-prefix.
/// An example would be '[0x03/0x10]'.
	friend std::ostream & operator<<( std::ostream & lhs, const rational & rhs ){
		return lhs
		<< std::hex
		<< "["
		<< "0x"
		<< std::setfill('0')
		<< std::setw(2) << rhs.counter 
		<< "/"
		<< "0x"
		<< std::setw(2) << rhs.denominator
		<< "]";
	}
/// \brief
/// multiply a rational by an integer
/// \details
/// This operator* multiplies a rational value by an integer value.
/// Every function onwards reduces the result before returning it.
	rational operator*( const int rhs ) const {
	rational res ( counter * rhs, denominator );
	res.reduce();
	return res;
	}
/// \brief
/// multiply a rational by a rational
/// \details
/// This operator* multiplies a rational value by a rational value.
	rational operator*( const rational & rhs ) const {
	rational res ( counter * rhs.counter, denominator * rhs.denominator );
	res.reduce();
	return res;
	}
/// \brief
/// add a rational to another rational
/// \details
/// This operator+= adds a rational value to a rational variable.
/// Because it is an operator+=, we need to change the original variable.
/// So the variable to the left hand side is passed as a pointer.
	rational & operator+=( const rational & rhs ){
		counter = counter * rhs.denominator + rhs.counter * denominator;
		denominator *= rhs.denominator;
		reduce();
		return *this;
	}
/// \brief
/// Multiply a rational by another rational
/// \details
/// This operator*= multiplies a rational value by a rational value.
/// Because it is an operator*=, we need to change the original variable.
/// So the variable to the left hand side is passed as a pointer.
	rational & operator*=( const rational & rhs ){
		counter *= rhs.counter;
		denominator *= rhs.denominator;
		reduce();
		return *this;
	}
};

#endif