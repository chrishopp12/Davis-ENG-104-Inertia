/*
ENG 104 - Inertia Calculator
Author:  Chris Hopp - 915866326
Version: 11.10.2018

*/

#ifndef _Rectangle_H
#define _Rectangle_H

#include <iostream>
#include "Crosssection.h"
#include "Shape.h"

using namespace std;

class Rectangle : public Shape {
private:
	int locationX;
	int locationY;
	int density;
	int base;
	int height;

public:
	Rectangle(int, int, int, int, int);



	int findCentroidX();
	int findCentroidY();
	double calcInertiaX();
	double calcInertiaY();
	double calcArea();
};


#endif
