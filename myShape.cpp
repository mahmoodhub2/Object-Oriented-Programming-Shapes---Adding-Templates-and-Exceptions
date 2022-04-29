//myShape.cpp
// this is the file where we do the test by allowing input into the class's methods and functions


#include <stdio.h>
#include <stdlib.h>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "CircleSquare.h"
#include "Moreau.h"
#pragma warning(disable:4996)

#include <iostream>
using namespace std;



int main(void) {


	Circle round1("red", 5.5);
	Circle round2("blue", 10.5);

	Square square1("orange", 5);
	Square square2("purple", 12);
	


	Square playASquare = combineShape <Square>(square2, square1);
	playASquare.Show();

	CircleSquare playARoundSquare = combineDiffrentShape <Square, Circle, CircleSquare> (square2, round1);
	if (square2.GetSideLengthException() != 0) {
		cout << "\nsidelength is smaller than the diameter!" << endl;
	}
	else {
		playARoundSquare.show();
	}
	

	playARoundSquare = combineDiffrentShape <Square, Circle, CircleSquare>(square1, round2);
	if (square1.GetSideLengthException() != 0) {
		cout << "\nsidelength is smaller than the diameter!" << endl;
	}
	else {
		playARoundSquare.show();
	}
	

	return 0;
}

