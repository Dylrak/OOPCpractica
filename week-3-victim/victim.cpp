#include "victim.hpp"

victim::victim(window & w, const vector & start, const vector & end, const bool & dying ):
	rectangle(w, start, end),
	dying ( dying )
{}

void victim::interact(drawable & other) {
	if( this != & other){
		if( overlaps( other )){
			dying = true;
		}
	}
}

void victim::update() {
	if (dying) {
		if (size.x == 0 && size.y == 0) {
			*this = victim(w, vector (0, 0), vector (0, 0), false );
		} else {
			*this = victim(w, location + vector (1, 1), location + size - vector(1, 1), true);
		}
	}
}