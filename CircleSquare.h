/* -- this is a CLASS COMMENT --
	NAME	:	CircleSquare
	PURPOSE :	This is the child class of Shape The purpose of this class is to
				realistically model the attributes and calculations of
				a CircleSquare.

*/



#ifndef __CircleSquare_H__
#define __CircleSquare_H__
#include "CircleSquare.h"
#include "Shape.h"
#define PI 3.1415926;


class CircleSquare : public Shape {

private:
	double sideLength;
	double radius;

public:

	CircleSquare(string newColor, string newName, double newSideLength, double newRadius);
	CircleSquare(void);

	~CircleSquare(void);

	void SetSideLength(double newSideLength);
	double GetSideLength(void);


	void SetRadius(double newRadius);
	double GetRadius(void);

	void show(void);


	CircleSquare operator+(const CircleSquare& op2);
	const CircleSquare& operator=(const CircleSquare& op2);

	/*Circle operator*(const Circle& op2);
	bool operator==(const Circle& op2) const;*/


	virtual double Perimeter(void);
	virtual double Area(void);
	virtual double OverallDimension(void);
};


#endif