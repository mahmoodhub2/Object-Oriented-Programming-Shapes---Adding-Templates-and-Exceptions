/* -- this is a FILEHEADER COMMENT --
	NAME	:	Square.cpp
	PURPOSE :	This file contains the methods and constructors that modify the shape's class attributes

*/


#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Square.h"
#include "Shape.h"
#include <iostream>

using namespace std;


/*  -- Method Header Comment
	Name	: Square -- CONSTRUCTOR
	Purpose : to instantiate a new Square object - given a set of attribute values
	Inputs	:	name	String		name of the shape
	Inputs	:	color	String		color of the shape

	Outputs	:	NONE
	Returns	:	Nothing
*/
Square::Square(string newColor, float newSideLength) : Shape("Square", newColor)
{

	if (newSideLength < 0.00) {
		newSideLength = 0.00;
	}

	sideLength = newSideLength;
	sideLengthExceptionHandler = 0;
}


/*  -- Method Header Comment
	Name	: Square -- CONSTRUCTOR
	Purpose : to instantiate a new Square object - given a set of attribute values
	Inputs	:	none
	Outputs	:	NONE
	Returns	:	Nothing
*/
Square::Square(void) : Shape() {
	sideLength = 0.00;
}


/*  -- Method Header Comment
	Name	: Square -- DESTRUCTOR
	Purpose : to destroy the constructor
	Inputs	:	none
	Outputs	:	NONE
	Returns	:	Nothing
*/
Square:: ~Square(void) {
	printf("The square is squished ..");
}


/*  -- Method Header Comment
	Name	: SetSideLength -- MUTTATOR
	Purpose : to set the sidelength attribute with the inputted one
	Inputs	:	newSideLength	float		side length of the square

	Outputs	:	NONE
	Returns	:	Nothing
*/
void Square::SetSideLength(float newSideLength) {

	if (newSideLength < 0.00) {
		newSideLength = 0.00;
	}

	sideLength = newSideLength;
}


/*  -- Method Header Comment
	Name	: GetSideLength -- ACCESSORR
	Purpose : to return the value of the sidelength attribute
	Inputs	:	none

	Outputs	:	NONE
	Returns	:	the side length
*/
float Square::GetSideLength(void) {
	return sideLength;
}

float Square::GetSideLength(void) const {
	return sideLength;
}


/*  -- Method Header Comment
	Name	: Perimeter -- FUNCTION
	Purpose : to calculate the permieter of the square
	Inputs	:	none

	Outputs	:	NONE
	Returns	:	permieter of the square
*/
double Square::Perimeter(void) {
	return 4 * GetSideLength();
}

/*  -- Method Header Comment
	Name	: Area -- FUNCTION
	Purpose : to calculate the Area of the square
	Inputs	:	none

	Outputs	:	NONE
	Returns	:	Area of the square
*/
double Square::Area(void) {
	return pow(GetSideLength(), 2);
}


/*  -- Method Header Comment
	Name	: OverallDimension -- FUNCTION
	Purpose : to calculate the OverallDimension of the square
	Inputs	:	none

	Outputs	:	NONE
	Returns	:	GetSideLength's value
*/
double Square::OverallDimension(void) {
	return GetSideLength();
}



// overloaded addition operator
// adds the LHS's color to the resultant
// adds the LHS's radius and the RHS's radius to the resultant
// returns the resultant
Square Square::operator+(const Square& op2)
{
	Square temp;
	temp.SetColor(this->GetColor());
	temp.sideLength = this->sideLength + op2.sideLength;
	return temp;
}

// overloaded addition operator
// adds the LHS's color to the resultant
// adds the RHS's radius  to the resultant
// adds the LHS's sidelength  to the rsultant
// returns the resultant
CircleSquare Square::operator+(const Circle& op2) {
	CircleSquare temp;
	temp.SetName("Square-Circle");
	temp.SetColor(this->GetColor());
	double newSideLength = this->GetSideLength();
	if (newSideLength >= 0) {
		double diameter = 0;
		diameter = op2.GetRadius() * 2.0;
		if (newSideLength >= diameter) {
			temp.SetSideLength(newSideLength);
		}
		else {
			sideLengthExceptionHandler++;
		}
	}
	temp.SetRadius(op2.GetRadius());
	return temp;
}
int Square::GetSideLengthException(void) {
	return sideLengthExceptionHandler;
}


// overloaded multplication operator
// adds the RHS's color to the resultant
// adds the LHS's radius and the RHS's radius to the resultant
// returns the resultant
Square Square::operator*(const Square& op2)
{
	Square temp;
	temp.SetColor(op2.GetColor());
	temp.sideLength = this->sideLength * op2.sideLength;
	return temp;
}



// overloaded assignment operator
// adds the RHS's color to the LHS
// adds the RHS's radius to the LHS's radius 
// returns a pointer to the LHS
const Square& Square::operator=(const Square& op2)
{
	if (this != &op2) {
		this->SetColor(op2.GetColor());
		this->sideLength = op2.sideLength;
	}
	return *this;
}


// overloaded comparison operator
// it compares the LHS to RHS
// returns true if they're equal false if not
bool Square::operator==(const Square& op2) const
{
	float reduced = this->sideLength - op2.GetSideLength();
	if ((this->GetColor() == op2.GetColor()) && (reduced == 0.00000000)) {
		return true;
	}

	return false;
}





/*  -- Method Header Comment
	Name	: Show -- FUNCTION
	Purpose : to show the values of the square attributes
	Inputs	:	none

	Outputs	:	the values of the square attributes
	Returns	:	none
*/
void Square::Show(void) {
	printf("\n\n");
	cout << "name\t\t: " << GetName() << "\n";
	cout << "color\t\t: " << GetColor() << "\n";
	printf("side-length\t: %f\n", GetSideLength());
	printf("Perimeter\t: %f\n", Perimeter());
	printf("Area\t\t: %f\n", Area());
}