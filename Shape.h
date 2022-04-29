/* -- this is a CLASS COMMENT --
	NAME	:	Shape
	PURPOSE :	This is the parent class The purpose of this class is to
				realistically model the attributes and calculations of
				a shape.

*/


#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <string>
#include <stdio.h>
using namespace std;

class Shape {

private:
	string name; // the string name
	string color; // the color name


public:
	Shape(string newName, string newColor); // constructor that takes the name and color and sets them.
	Shape(void); // default constructor that sets the two attributes.
	Shape(string newName);
	virtual ~Shape(void);

	bool SetName(string newName); //muattor that sets the name

	virtual string GetName(void); //accessor that gets the name
	virtual string GetName(void) const; //accessor that gets the name

	bool SetColor(string newColor); //mutator that sets the color
	string GetColor(void); //accessor that gets the color
	string GetColor(void) const; //accessor that gets the color

	// pure virtual functions
	virtual double Perimeter(void) = 0;
	virtual double Area(void) = 0;
	virtual double OverallDimension(void) = 0;
};

#endif