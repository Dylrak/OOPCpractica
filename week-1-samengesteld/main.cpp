#include "train.hpp"
#include "window.hpp"
#include <conio.h>
#include <iostream>
using namespace std;
//Edit this to get different wagons.
const int amount_of_wagons = 4;

//This program crashes after 10 or so seconds, so switch to the console screen and start spamming the numbers on your keyboard.
int main(int argc, char **argv){
	//Initiating window and train
	window w( 128, 64, 2 );
	train choochoo(w, amount_of_wagons);
	choochoo.print();
	//From here on out is threadblocking tomfoolery. It probably crashes because of getchar() so just edit the amount of wagons variable at the top.
//	int input;
//	cout << "Type the amount of wagons you want (1 through 9) or q to quit:\n";
//	//By typing 0-9 into the program we can change the amount of wagons.
//	while ((input = getchar()) != 'q') {
//		if (input < '1' || input > '9') {
//			cin.clear();
//		} else {
//			w.clear_screen();
//			amount_of_wagons = input - '0';
//			train choochoo(w, amount_of_wagons);
//			choochoo.print();
//		}
//	}
//	//After entering q, we close the program.
//	delete(& choochoo);
//	delete(& w);
//	return 0;
}
