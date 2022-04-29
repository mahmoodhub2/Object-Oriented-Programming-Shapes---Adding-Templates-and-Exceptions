/* -- this is a CLASS COMMENT --
	NAME	:	Square
	PURPOSE :	This is the child class of Shape The purpose of this class is to
				realistically model the attributes and calculations of
				a Square.

*/


#ifndef __SQUARE_H__
#define __SQUARE_H__
#include "Shape.h"
#include "Circle.h"
#include "CircleSquare.h"


class Square : public Shape {

private:
	float sideLength; //the sidelength of the square
	int sideLengthExceptionHandler;


public:
	Square(string newColor, float newSideLength); // constructor to initlize the two attributes
	Square(void); // default constructor that inilizes the two attributes

	~Square(void); // destructor to destroy the constructor

	void SetSideLength(float newSideLength); // muttator to set the inputted side length
	float GetSideLength(void); // accessor to return the the sidelength value
	float GetSideLength(void) const; // accessor to return the the sidelength value


	void Show(void); // function to print out the current values

	//virctual functions
	virtual double Perimeter(void);
	virtual double Area(void);
	virtual double OverallDimension(void);

	Square operator+(const Square& op2);

	CircleSquare operator+(const Circle& op2);

	Square operator*(const Square& op2);
	const Square& operator=(const Square& op2);
	bool operator==(const Square& op2) const;

	int GetSideLengthException(void);
};



#endif