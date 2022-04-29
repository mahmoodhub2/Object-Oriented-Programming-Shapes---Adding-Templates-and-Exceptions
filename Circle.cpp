//Circle.cpp
// this is the source code of Circle class, where the methods modifies the attributes

#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Circle.h"
#include "Shape.h"
#include <iostream>

using namespace std;

#define PI 3.1415926;


/*  -- Method Header Comment
	Name	: Circle -- CONSTRUCTOR
	Purpose : to instantiate a new Circle object - given a set of attribute values
	Inputs	:	newRadius		float		Radius of the square
	Inputs	:	newColor		String		color of the square
	Outputs	:	NONE
	Returns	:	Nothing
*/
Circle::Circle(string newColor, float newRadius) : Shape("Circle", newColor) {
	if (newRadius < 0.00) {
		newRadius = 0.00;
	}
	radius = newRadius;


}


/*  -- Method Header Comment
	Name	: Circle -- CONSTRUCTOR
	Purpose : to instantiate a new Circle object - given a set of attribute values
	Outputs	:	NONE
	Returns	:	Nothing
*/
Circle::Circle(void) : Shape() {
	radius = 0.00;
}



/*  -- Method Header Comment
	Name	: Circle -- DESTRUCTOR
	Purpose : to destroy Circle object
	Outputs	:	message indicating the end of the circle
	Returns	:	Nothing
*/
Circle::~Circle(void) {
	printf("\nThe circle is broken..");
}



/*  -- Method Header Comment
	Name	: SetRadius -- MUTTATOR
	Purpose : to instantiate a new radius and preform validation on it
	Inputs	:	radius		float		radius of the square
	Outputs	:	NONE
	Returns	:	radius's value
*/
void Circle::SetRadius(float newRadius) {
	if (newRadius < 0.00) {
		newRadius = 0.00;
	}
	radius = newRadius;
}


/*  -- Method Header Comment
	Name	: GetRadius -- ACCESSOR
	Purpose : to return the value of the radius
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	radius float
*/
float Circle::GetRadius(void) {
	return radius;
}

float Circle::GetRadius(void) const {
	return radius;
}


/*  -- Method Header Comment
	Name	: Perimeter -- FUNCTION
	Purpose : to calculate the permieter of the Circle
	Inputs	:	none

	Outputs	:	NONE
	Returns	:	permieter of the Circle
*/
double Circle::Perimeter(void) {
	double perimeter = 2 * PI;
	return perimeter += perimeter * GetRadius();
}


/*  -- Method Header Comment
	Name	: Area -- FUNCTION
	Purpose : to calculate the Area of the Circle
	Inputs	:	none

	Outputs	:	NONE
	Returns	:	Area of the Circle
*/
double Circle::Area(void) {
	double radiusToThePowerOfTwo = pow(GetRadius(), 2);
	return radiusToThePowerOfTwo * PI;
}



/*  -- Method Header Comment
	Name	: OverallDimension -- FUNCTION
	Purpose : to calculate the OverallDimension of the Circle
	Inputs	:	none

	Outputs	:	NONE
	Returns	:	GetRadius's value
*/
double Circle::OverallDimension(void) {
	return 2 * GetRadius();
}


// overloaded addition operator
// adds the LHS's color to the resultant
// adds the LHS's radius and the RHS's radius to the resultant
// returns the resultant
Circle Circle::operator+(const Circle& op2)
{
	Circle temp;
	temp.SetColor(this->GetColor());
	temp.radius = this->radius + op2.radius;
	return temp;
}


// overloaded multplication operator
// adds the RHS's color to the resultant
// adds the LHS's radius and the RHS's radius to the resultant
// returns the resultant
Circle Circle::operator*(const Circle& op2)
{
	Circle temp;
	temp.SetColor(op2.GetColor());
	temp.radius = this->radius * op2.radius;
	return temp;
}

// overloaded assignment operator
// adds the RHS's color to the LHS
// adds the RHS's radius to the LHS's radius 
// returns a pointer to the LHS
const Circle& Circle::operator=(const Circle& op2)
{
	if (this != &op2) {
		this->SetColor(op2.GetColor());
		this->radius = op2.radius;
	}
	return *this;

}



// overloaded comparison operator
// it compares the LHS to RHS
// returns true if they're equal false if not
bool Circle::operator==(const Circle& op2) const
{
	float getrad = op2.GetRadius();
	float reducedVal = this->radius - getrad;
	if ((this->GetColor() == op2.GetColor()) && (reducedVal == 0.00000000)) {
		return true;
	}

	return false;
}




/*  -- Method Header Comment
	Name	: Show -- FUNCTION
	Purpose : to show the values of the Circle attributes
	Inputs	:	none

	Outputs	:	the values of the Circle attributes
	Returns	:	none
*/
void Circle::Show(void) {
	printf("\n\n");
	cout << "name\t\t: " << GetName() << "\n";
	cout << "color\t\t: " << GetColor() << "\n";
	printf("radius\t\t: %f\n", GetRadius());
	printf("circumference\t: %f\n", OverallDimension());
	printf("Area\t\t: %f\n", Area());
}