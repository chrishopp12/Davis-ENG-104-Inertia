/*
ENG 104 - Inertia Calculator
Author:  Chris Hopp - 915866326
Version: 11.10.2018

*/

#include "Crosssection.h"
#include "Shape.h"
#include "Circle.h"

#include <fstream>

#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

extern ofstream output;
using namespace std;


Circle::Circle(int locationX, int locationY, int density, int radius) : Shape(locationX, locationY, density) {

}

int Circle::findCentroidX() {
	int centroidX = locationX;
	return locationX;
}

int Circle::findCentroidY() {
	int centroidY = locationY;
	return centroidY;
}

double Circle::calcInertiaX() {
	double iX = ((radius^4) * M_PI/4);
	return iX;
}

double Circle::calcInertiaY() {
	double iY = ((radius ^ 4) * M_PI / 4);
	return iY;
}

double Circle::calcArea() {
	double area = (density * (radius ^ 2) * M_PI);
	return area;
}