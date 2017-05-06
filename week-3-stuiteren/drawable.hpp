#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <ostream>
#include "window.hpp"
#include "vector.hpp"

class drawable {
protected:
   window w;
   vector location;
   vector size;
   //This vector depicts which speed axis will be inverted if an object hits this drawable.
public:
   drawable( window & w, const vector & location, const vector & size, const vector & bounce = vector(1, 1) );   
   bool overlaps( const drawable & other );
   virtual void draw() = 0;
   virtual void update(){}
   virtual void interact( drawable & other ){}
   
   std::ostream & print( std::ostream & out ) const;
   
   vector bounce;
};

std::ostream & operator<<( std::ostream & lhs, const drawable & rhs );

#endif // DRAWABLE_HPP
