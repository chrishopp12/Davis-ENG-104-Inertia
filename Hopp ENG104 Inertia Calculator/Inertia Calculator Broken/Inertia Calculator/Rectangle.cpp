/*
ENG 104 - Inertia Calculator
Author:  Chris Hopp - 915866326
Version: 11.10.2018

*/

#include "Crosssection.h"
#include "Shape.h"
#include "Rectangle.h"

#include <fstream>

extern ofstream output;
using namespace std;

Rectangle::Rectangle(int locationX, int locationY, int density, int base, int height) : Shape(locationX, locationY, density) {
	locationX = locationX;
	locationY = locationY;
	density = density;
	base = base;
	height = height;
}

int Rectangle::findCentroidX() {
	int centroidX = (locationX + (base / 2));
	return centroidX;
}

int Rectangle::findCentroidY() {
	int centroidY = (locationY + (height / 2));
	return centroidY;
}

double Rectangle:: calcInertiaX() {
	double iX = ((1/12) * base * (height ^ 3));
	return iX;
}

double Rectangle:: calcInertiaY() {
	double iY = ((1/12) * height * (base ^ 3));
	return iY;
}

double Rectangle::calcArea() {
	double area = (density * base * height);
	return area;
}