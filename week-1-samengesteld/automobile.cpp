#include "automobile.hpp"

automobile::print()
{
	for (int i = 0; i < circles; i++) {
		circle wheel (w, 64, 32, 8);
		wheel.print();
	}
}