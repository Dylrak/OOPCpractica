#ifndef TRAIN_HPP
#define TRAIN_HPP

#include "wagon.hpp"
#include <vector>
class train {
private:
	//Amount of wagons our train has
	int wagon_amount;
	window & w;
	std::vector<wagon> wagons;
public:
	train(window & w, int wagon_amount):
		wagon_amount( wagon_amount ),
		w( w )
	{
		//We start by figuring out the size of each 'wagon', including padding. This is the size of the screen divided by the amount of wagon_amount required.
		int wagon_width = w.screen_width() / wagon_amount;
		//Next, we calculate the size of the padding. This will be 12,5% of the wagon size.
		int padding_width = wagon_width / 8;
		//The width of our cabin is the width of our wagon minus padding. 
		int cabin_width = wagon_width - padding_width * 2;
		//The height of our cabin is 75% of our width.
		int cabin_height = cabin_width * 3 / 4;
		//The upper and lower boundaries of our cabins are the same for all wagon_amount so we calculate them here.
		int cabin_upper = (w.screen_height() - cabin_height) / 2;
		int cabin_lower = (w.screen_height() + cabin_height) / 2;
		int cabin_left, cabin_right = -1;
		for (int i = 0; i < wagon_amount; i++) {
			cabin_left =  wagon_width * i + padding_width;
			cabin_right = wagon_width * (i + 1) - padding_width;
			line connector (w, cabin_right, cabin_lower - 5, cabin_right + padding_width * 2, cabin_lower - 5);
			line dummy (w, 0, 0, 0, 0);
			if (i + 1 < wagon_amount) {
				wagons.push_back(wagon (w, cabin_left, cabin_upper, cabin_right, cabin_lower, connector, true));
			} else {
				wagons.push_back(wagon (w, cabin_left, cabin_upper, cabin_right, cabin_lower, dummy, false));
			}
		}
	}
	void print();
};

#endif // TRAIN_HPP
