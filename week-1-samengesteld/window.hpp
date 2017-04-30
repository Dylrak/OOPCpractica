// example:
// declaration of a window class

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "windows.h"

class window {
   int x_size;
   int y_size;
   int scale;
   
   // needed to use the OS window
   HDC hdc;
   
public:
   window( int x_size, int y_size, int scale );
   void draw( int x, int y );
   void clear();
   void clear_screen();
   int screen_width();
   int screen_height();
};

#endif // WINDOW_HPP
