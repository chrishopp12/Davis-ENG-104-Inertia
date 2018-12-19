/*
ENG 104 - Inertia Calculator
Author:  Chris Hopp - 915866326
Version: 11.10.2018

*/

#ifndef _SHAPE_H
#define _SHAPE_H

#include <iostream>
#include "Crosssection.h"


using namespace std;

class Shape {
protected:
	int locationX;
	int locationY;
	int density;

public:
	Shape(int, int, int);
	

	virtual int findCentroidX()=0;
	virtual int findCentroidY()=0;
	virtual double calcInertiaX()=0;
	virtual double calcInertiaY()=0;
	virtual double calcArea()=0;
};

#endif
