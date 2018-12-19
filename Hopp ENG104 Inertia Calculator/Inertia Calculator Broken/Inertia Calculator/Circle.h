/*
ENG 104 - Inertia Calculator
Author:  Chris Hopp - 915866326
Version: 11.10.2018

*/

#ifndef _Circle_H
#define _Cirlce_H

#include <iostream>
#include "Crosssection.h"
#include "Shape.h"

using namespace std;

class Circle : public Shape {
private:
	int radius;

public:
	Circle(int, int, int, int);



	int findCentroidX();
	int findCentroidY();
	double calcInertiaX();
	double calcInertiaY();
	double calcArea();
};


#endif
