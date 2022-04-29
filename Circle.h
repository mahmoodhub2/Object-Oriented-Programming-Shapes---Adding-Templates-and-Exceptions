/* -- this is a CLASS COMMENT --
	NAME	:	Circle
	PURPOSE :	This is the child class of Shape The purpose of this class is to
				realistically model the attributes and calculations of
				a Circle.

*/


#ifndef __CIRCLE_H__
#define __CIRCLE_H__
#include "Shape.h"

class Circle : public Shape {

private:
	float radius; // the radius of the circle


public:



	Circle(string newColor, float newRadius); //constructor to inilize the attributes of the cirle
	Circle(void); // defualt constructor to inlizliaze the attreibutes of the cirle

	~Circle(void); // destructor to destroy the cirle

	void SetRadius(float newRadius); // setter to set the radius attribute
	float GetRadius(void); // getter, to retunr the radius attribute
	float GetRadius(void) const; // getter, to retunr the radius attribute


	void Show(void); // function to print the  values of the attributes

	//virtual functions
	virtual double Perimeter(void);
	virtual double Area(void);
	virtual double OverallDimension(void);



	Circle operator+(const Circle& op2);
	Circle operator*(const Circle& op2);
	const Circle& operator=(const Circle& op2);
	bool operator==(const Circle& op2) const;


};



#endif