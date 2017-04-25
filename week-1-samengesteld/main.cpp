#include "train.hpp"
const int amount_of_wagons = 2;
int main(int argc, char **argv){
	window w( 128, 64, 2 );
	train choochoo(w, amount_of_wagons);
	choochoo.print();
}
