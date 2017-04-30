#include "train.hpp"

void train::print()
{
	//We start by figuring out the size of each 'wagon', including padding. This is the size of the screen divided by the amount of wagons required.
	int wagon_width = w.screen_width() / wagons;
	//Next, we calculate the size of the padding. This will be 12,5% of the wagon size.
	int padding_width = wagon_width / 8;
	//The width of our cabin is the width of our wagon minus padding. 
	int cabin_width = wagon_width - padding_width * 2;
	//The height of our cabin is 75% of our width.
	int cabin_height = cabin_width * 3 / 4;
	//The upper and lower boundaries of our cabins are the same for all wagons so we calculate them here.
	int cabin_upper = (w.screen_height() - cabin_height) / 2;
	int cabin_lower = (w.screen_height() + cabin_height) / 2;
	int cabin_left, cabin_right = -1;
	//Now we have our dimensions, we can start drawing the wagons.
	for (int i = 0; i < wagons; i++) {
		cabin_left =  wagon_width * i + padding_width;
		cabin_right = wagon_width * (i + 1) - padding_width;
		wagon waggie (w, cabin_left, cabin_upper, cabin_right, cabin_lower);
		waggie.print();
	//If there are more wagons to come, we draw a line to the right of our current cabin to indicate the wagons are connected.
		if (i + 1 < wagons) {
			line connector (w, cabin_right, cabin_lower - 5, cabin_right + padding_width * 2, cabin_lower - 5);
			connector.print();
		}
	}
}