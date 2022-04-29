//Shape.cpp
// this is the source code of Shape class, where the methods modifies the attributes


#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Shape.h"
using namespace std;



/*  -- Method Header Comment
	Name	: Shape -- CONSTRUCTOR
	Purpose : to instantiate a new Shape object - given a set of attribute values
	Inputs	:	newName		String		name of the square
	Inputs	:	newColor	String		color of the square

	Outputs	:	NONE
	Returns	:	Nothing
*/
Shape::Shape(string newName, string newColor) {
	if (newName == "Circle" || newName == "Square" || newName == "Square-Circle" || newName == "Circle-Square") {
		name = newName;
	}

	else {
		name = "Unkown";
	}

	if (newColor == "red" || newColor == "green" || newColor == "blue" || newColor == "purple" || newColor == "pink" || newColor == "orange" || newColor == "Undefined") {

		color = newColor;
		}

	else {
		color = "Undefined";

	}
}


/*  -- Method Header Comment
	Name	: Shape -- CONSTRUCTOR
	Purpose : to instantiate a new Shape object - given a set of attribute values
	Outputs	:	NONE
	Returns	:	Nothing
*/
Shape::Shape(void) {
	name = "Unkown";
	color = "Undefined";
}

Shape::Shape(string newName) {
	name = newName;
}


Shape::~Shape(void) {
	printf("\nThe shape is broken..\n");
}


/*  -- Method Header Comment
	Name	: SetName -- MUTTATOR
	Purpose : to instantiate a new Shape name and preform validation on it
	Inputs	:	newName		String		name of the square
	Outputs	:	NONE
	Returns	:	Nothing
*/
bool Shape::SetName(string newName) {
	if (newName == "Circle" || newName == "Square" || newName == "Square-Circle" || newName == "Circle-Square" || newName == "undefined") {
		name = newName;
		return true;
	}
	else {
		return false;
	}
}


/*  -- Method Header Comment
	Name	: GetName -- ACCESSOR
	Purpose : to return the value of the name
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	name string
*/
string Shape::GetName(void) {
	return name;
}

string Shape::GetName(void) const {
	return name;
}



/*  -- Method Header Comment
	Name	: SetColor -- MUTTATOR
	Purpose : to instantiate a new Shape color and preform validation on it
	Inputs	:	newColor		String		color of the square
	Outputs	:	NONE
	Returns	:	true if color is valid or false if not
*/
bool Shape::SetColor(string newColor) {
	if (newColor == "red" || newColor == "green" || newColor == "blue" || newColor == "purple" || newColor == "pink" || newColor == "orange" || newColor == "Undefined") {
		color = newColor;
		return true;
	}

	else {
		return false;
	}
}


/*  -- Method Header Comment
	Name	: GetColor -- ACCESSOR
	Purpose : to return the value of the color
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	color string
*/
string Shape::GetColor(void) {
	return color;
}


string Shape::GetColor(void) const {
	return color;
}

