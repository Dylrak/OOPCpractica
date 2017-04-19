#include "filled_rectangle.hpp"

int main(int argc, char **argv) {
	window w( 128, 64, 2 );
	filled_rectangle rekt(w, 32, 16, 96, 48);
	rekt.print();
}