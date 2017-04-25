#ifndef AUTOMOBILE_HPP
#define AUTOMOBILE_HPP

#include "circle.hpp"

class automobile
{
private:
int circles;
public:
	automobile(int circles):
	circles ( circles )
	{}
	void print();
};

#endif // AUTOMOBILE_HPP
