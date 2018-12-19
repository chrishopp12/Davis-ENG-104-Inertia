/*
ENG 104 - Inertia Calculator
Author:  Chris Hopp - 915866326
Version: 11.10.2018

*/

#include "Crosssection.h"
#include "Shape.h"

#include <fstream>

extern ofstream output;
using namespace std;

Shape::Shape(int locationX, int locationY,  int density) {
	locationX = locationX;
	locationY = locationY;
	density = density;
}


//int Shape::findCentroidX()=0 {}
//int Shape::findCentroidY() =0{}
//double Shape::calcInertiaX() {};
//double Shape::calcInertiaY() {};
//double Shape::calcArea() {};
