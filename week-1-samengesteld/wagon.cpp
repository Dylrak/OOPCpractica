#include "wagon.hpp"

void wagon::print()
{
	cabin.print();
	left_wheel.print();
	right_wheel.print();
	if (has_connector) {
		connector.print();
	}
}
