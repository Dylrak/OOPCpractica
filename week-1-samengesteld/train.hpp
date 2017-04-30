#ifndef TRAIN_HPP
#define TRAIN_HPP

#include "wagon.hpp"
#include "line.hpp"

class train {
private:
	//Amount of wagons our train has
	int wagons;
	window & w;
public:
	train(window & w, int wagons):
	wagons( wagons ),
	w( w )
	{}
	void print();
};

#endif // TRAIN_HPP
