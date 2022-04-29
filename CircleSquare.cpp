/* -- this is a FILEHEADER COMMENT --
	NAME	:	CircleSquare.cpp
	PURPOSE :	This file contains the methods and constructors that modify the CircleSquare's class attributes

*/


#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CircleSquare.h"
#include "CircleSquare.h"
#include <iostream>

using namespace std;


/*  -- Method Header Comment
	Name	:	CircleSquare -- CONSTRUCTOR
	Purpose :	to instantiate a new CircleSquare object - given a set of attribute values
	Inputs	:	name		String		name of the CircleSquare
	Inputs	:	color		String		color of the CircleSquare
	Inputs	:	sideLength	double		sideLength of the CircleSquare
	Inputs	:	radius		double		radius of the CircleSquare

	Outputs	:	messages to indicate the that the radius or sidelength are invalid
	Returns	:	Nothing
*/
CircleSquare::CircleSquare(string newColor, string newName, double newSideLength, double newRadius) : Shape(newName, newColor) {
	if (newName == "Circle-Square") {
		if (newRadius >= 0) {
			double diameter = newRadius * 2.0;
			if (diameter >= newSideLength) {
				radius = newRadius;
			}
			else {				
				diameter = newSideLength * 1.5;
				radius  = diameter / 2.0;
			}
		}
		else {
			cout << "Radius is unvalid!" << endl;
		}
	}

	if (newName == "Square-Circle") {
		if (newSideLength >= 0) {
			double diameter = newRadius * 2.0;
			if (newSideLength >= diameter) {
				sideLength = newSideLength;
			}
			else {
				sideLength = 1.5 * diameter;
			}
		}
	}

	if (newName != "Circle-Square" || newName != "Square-Circle") {
		newName = "Circle-Square";
		if (newRadius >= 0) {
			double diameter = newRadius * 2.0;
			if (diameter >= newSideLength) {
				radius = newRadius;
			}
			else {
				diameter = newSideLength * 1.5;
				radius = diameter / 2.0;
			}
		}
		else {
			cout << "Radius is unvalid!" << endl;
		}
	}	
}

/*  -- Method Header Comment
	Name	: CircleSquare -- CONSTRUCTOR
	Purpose : to instantiate a new CircleSquare object - given a set of attribute values
	Inputs	:	none
	Outputs	:	NONE
	Returns	:	Nothing
*/
CircleSquare::CircleSquare(void) : Shape("Circle-Square", "Undefined")
{
	sideLength = 0.00;
	radius = 0.00;
}


/*  -- Method Header Comment
	Name	: CircleSquare -- DESTRUCTOR
	Purpose : to destroy the constructor
	Inputs	:	none
	Outputs	:	message indicating the constructor has been freed
	Returns	:	Nothing
*/
CircleSquare::~CircleSquare() {
	cout << "\nClosing the CircleSquare Ranch .." << endl;
}





/*  -- Method Header Comment
	Name	: SetSideLength -- MUTTATOR
	Purpose : to set the sidelength attribute with the inputted one
	Inputs	:	newSideLength	float		side length of the CircleSquare

	Outputs	:	NONE
	Returns	:	Nothing
*/
void CircleSquare::SetSideLength(double newSideLength) {
	if (newSideLength >= 0) {
		double diameter = radius * 2.0;
		if (newSideLength >= diameter) {
			sideLength = newSideLength;
		}
		else {
			sideLength = 1.5 * diameter;
		}
	}
}



/*  -- Method Header Comment
	Name	: GetSideLength -- ACCESSORR
	Purpose : to return the value of the sidelength attribute
	Inputs	:	none

	Outputs	:	NONE
	Returns	:	the side length
*/
double CircleSquare::GetSideLength(void) {
	return sideLength;
}


/*  -- Method Header Comment
	Name	: SetRadius -- MUTTATOR
	Purpose : to instantiate a new radius and preform validation on it
	Inputs	:	radius		double		radius of the CircleSuqare
	Outputs	:	NONE
	Returns	:	radius's value
*/
void CircleSquare::SetRadius(double newRadius) {

		if (newRadius >= 0) {
			double diameter = newRadius * 2.0;
			if (diameter >= sideLength) {
				radius = newRadius;
			}
			else {
				diameter = sideLength * 1.5;
				radius = diameter / 2.0;
			}
		}
	
}


/*  -- Method Header Comment
	Name	: GetRadius -- ACCESSOR
	Purpose : to return the value of the radius
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	radius float
*/
double CircleSquare::GetRadius(void) {
	return radius;
}


/*  -- Method Header Comment
	Name	: Perimeter -- FUNCTION
	Purpose : to calculate the permieter of the Circlesquare
	Inputs	:	none

	Outputs	:	NONE
	Returns	:	permieter of the square
*/
double CircleSquare::Perimeter(void) {
	if (GetName() == "Circle-Square") {
		double perimeter = 2 * PI;
		return perimeter += perimeter * GetRadius();
	}

	else{
		return 4 * GetSideLength();
	}
}


/*  -- Method Header Comment
	Name	: Area -- FUNCTION
	Purpose : to calculate the Area of the square
	Inputs	:	none

	Outputs	:	NONE
	Returns	:	Area of the square
*/
double CircleSquare::Area(void) {
	if (GetName() == "Square-Circle") {
		return pow(GetSideLength(), 2);

	}

	else {
		double radiusToThePowerOfTwo = pow(GetRadius(), 2);
		return radiusToThePowerOfTwo * PI;
	}
}



/*  -- Method Header Comment
	Name	: OverallDimension -- FUNCTION
	Purpose : to calculate the OverallDimension of the Circle-Square
	Inputs	:	none

	Outputs	:	NONE
	Returns	:	GetSideLength's value
*/
double CircleSquare::OverallDimension(void) {
	if (GetName() == "Circle-Square") {
		return 2 * GetRadius();
	}
	else {
		return GetSideLength();
	}
}


// overloaded addition operator
// adds the LHS's color to the resultant
// adds the LHS's radius and the RHS's radius to the resultant
// adds the LHS's sideLength and the RHS's sideLength to the resultant
// returns the resultant
CircleSquare CircleSquare::operator+(const CircleSquare& op2) {
	if ((this->GetName() == "Circle-Square" && op2.GetName() == "Circle-Square") || (this->GetName() == "Square-Circle" && op2.GetName() == "Square-Circle")) {
		CircleSquare temp;
		temp.SetColor(this->GetColor());
		temp.radius = this->radius + op2.radius;
		temp.sideLength = this->sideLength + op2.sideLength;

		return temp;
	}


	cout << "Type does not exist!";
}


// overloaded assignment operator
// adds the RHS's color to the LHS
// adds the RHS's radius to the LHS's radius 
// adds the RHS's sideLength to the LHS's sideLength 
// returns a pointer to the LHS
const CircleSquare& CircleSquare::operator=(const CircleSquare& op2)
{
	if (this != &op2) {
		this->SetName(op2.GetName());
		this->SetColor(op2.GetColor());
		this->radius = op2.radius;
		this->sideLength = op2.sideLength;
	}
	return *this;
}



/*  -- Method Header Comment
	Name	: Show -- FUNCTION
	Purpose : to show the values of the Circlesquare attributes
	Inputs	:	none

	Outputs	:	the values of the square attributes
	Returns	:	none
*/
void CircleSquare::show(void) {
	cout << "Shape Information" << endl;
	cout << "Name:\t" << GetName() << endl;
	cout << "Color:\t" << GetColor() << endl;
	if (GetName() == "Circle-Square") {
		cout << "Circle\n";
		cout << "\tRadius:\t" << GetRadius() << endl;
		cout << "\tCircumference:\t" << OverallDimension() << endl;
		cout << "\tArea:\t" << Area() << endl;

		cout << "Contained Square" << endl;
		cout << "\tSideLength:\t" << GetSideLength() << endl;
		cout << "\tPerimeter:\t" << Perimeter() << endl;
		cout << "\tArea:\t" << Area() << endl;
	}
	else if (GetName() == "Square-Circle") {
		cout << "Square\n";
		cout << "\tSideLength:\t" << GetSideLength() << endl;
		cout << "\tPerimeter:\t" << Perimeter() << endl;
		cout << "\tArea:\t" << Area() << endl;

		cout << "Contained Circle\n";
		cout << "\tRadius:\t" << GetRadius() << endl;
		cout << "\tCircumference:\t" << OverallDimension() << endl;
		cout << "\tArea:\t" << Area() << endl;
	}

}



