#include "train.hpp"

void train::print()
{
	for (int i = 0; i < wagons; i++) {
		circle wheel (w, 64, 32, 16);
		wheel.print();
	}
}