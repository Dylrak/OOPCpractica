#ifndef VECTOR_HPP
#define VECTOR_HPP
/// @file

#include <iostream>
/// \brief
/// vector ADT
/// \details
/// This is an ADT that implements vectors.
/// The x- & y-values are stored as two any class given.
/// The appropriate constructors and operators are provided.
class vector
{
private:
	int x, y;
public:
/// \brief
/// constructor from explicit values
/// \details
/// This constructor initializes a vector from the x- & y-values passed as parameter.
	vector(int x, int y):
		x ( x ), y ( y )
	{}
/// \brief
/// compare two vector values
/// \details
/// This operator tests for equality. It returns true
/// if the [x, y]-values of both operands are equal.
	bool operator==( const vector & rhs ) const {
		return ( x == rhs.x ) && ( y == rhs.y );
	}
/// \brief
/// output operator for a vector
/// \details
/// This operator<< prints a constructor in the format
/// (x, y) where both values are printed as
/// decimal values. An example would be '(3, 15)'.
	friend std::ostream & operator<<( std::ostream & lhs, const vector & rhs ){
		return lhs
		<< "("
		<< rhs.x
		<< ", "
		<< rhs.y
		<< ")";
	}
/// \brief
/// Add a vector to a vector
/// \details
/// This operator+ adds a vector to a vector.
	vector operator+( const vector & rhs ) const {
		return vector ( x + rhs.x, y + rhs.y );
	}
/// \brief
/// add a vector to this vector
/// \details
/// This operator+= adds a vector to a vector.
/// Because it is an operator+=, we need to change the original variable.
/// So the variable to the left hand side is passed as a pointer.
	vector & operator+=( const vector & rhs ){
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
/// \brief
/// Subtract a vector from a vector
/// \details
/// This operator- substracts the right hand side vector from this vector.
	vector operator-( const vector & rhs ) const {
		return vector ( x - rhs.x, y - rhs.y );
	}
/// \brief
/// Subtract a vector from this vector
/// \details
/// This operator-= substracts the right hand side vector from this vector.
/// Because it is an operator-=, we need to change the original variable.
/// So the variable to the left hand side is passed as a pointer.
	vector & operator-=( const vector & rhs ){
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
/// \brief
/// multiply this vector by an integer
/// \details
/// This operator*= multiplies a vector by an integer.
/// Because it is an operator*=, we need to change the original variable.
/// So the variable to the left hand side is passed as a pointer.
	vector & operator*=( const int rhs ){
		x *= rhs;
		y *= rhs;
		return *this;
	}
/// \brief
/// Divide this vector by an integer
/// \details
/// This operator/= divides a vector by an integer.
/// Because it is an operator/=, we need to change the original variable.
/// So the variable to the left hand side is passed as a pointer.
	vector & operator/=( const int rhs ){
		x /= rhs;
		y /= rhs;
		return *this;
	}
};
//The next two parameters are outside of class scope.
/// \brief   
/// multiply a vector by an integer
/// \details
/// This operator* multiplies both vector values by an integer value.
vector operator*( vector lhs, const int rhs ) {
	return lhs *= rhs;
}
/// \brief   
/// multiply an integer by a vector
/// \details
/// This operator* multiplies both vector values by an integer value.
vector operator*(const int lhs, vector rhs ) {
	return rhs *= lhs;
}
//The next two parameters are outside of class scope.
/// \brief   
/// Divide a vector by an integer
/// \details
/// This operator/ divides both vector values by an integer value.
/// It is, of course, guarded from using zero division.
vector operator/( vector lhs, const int rhs ) {
	if (rhs != 0) {
		return lhs /= rhs;
	}
	return lhs;
}
#endif // VECTOR_HPP
