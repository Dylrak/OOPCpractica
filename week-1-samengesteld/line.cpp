// example:
// definition of the functions of a line class 

#include "line.hpp"

void line::print(){
}

line::line( int p_start_x, int p_start_y, int p_end_x, int p_end_y ){
   start_x = p_start_x;
   start_y = p_start_y;
   end_x   = p_end_x;
   end_y   = p_end_y;
}