/*
ENG 104 - Inertia Calculator
Author:  Chris Hopp - 915866326
Version: 11.10.2018

*/

#ifndef _CROSSSECTION_H
#define _CROSSSECTION_H

#include <iostream>
#include "Shape.h"

using namespace std;

class Crosssection {
protected: 
	int centroidX[100];
	int centroidY[100];
	double area[100];
	double inertiaX[100];
	double inertiaY[100];

public:


	Crosssection();
	Shape* interface();

	int numberOfShapes;


	double sectionArea;
	double sectionCentroidX;
	double sectionCentroidY;
	double sectionInertiaX;
	double sectionInertiaY;

	double calcSectionArea();
	double calcSectionCentroidX();
	double calcSectionCentroidY();
	double calcSectionInertiaX();
	double calcSectionInertiaY();

};

#endif