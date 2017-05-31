#include "train.hpp"

void train::print()
{
	for (int i = 0; i < wagon_amount; i++) {
		wagons[i].print();
	}
}