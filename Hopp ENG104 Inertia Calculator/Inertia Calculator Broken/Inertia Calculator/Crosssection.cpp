/*
ENG 104 - Inertia Calculator
Author:  Chris Hopp - 915866326
Version: 11.10.2018

*/

#include "Crosssection.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

#include <fstream>
#include <iostream>


extern ofstream output;

using namespace std;

//Crosssection::Crosssection(const Crosssection& cs1) {}

Crosssection::Crosssection() {

	cout << "Enter number of shapes" << endl;
	output << "Enter number of shapes" << endl;
	cin >> numberOfShapes;

	Shape** shapes = new Shape*[numberOfShapes];


	for (int i = 0; i < numberOfShapes; i++) {
		shapes[i] = interface();
	}
	for (int i = 0; i < numberOfShapes; i++) {
		centroidX[i] = shapes[i]->findCentroidX();
	}
	for (int i = 0; i < numberOfShapes; i++) {
		centroidY[i] = shapes[i]->findCentroidY();
	}
	for (int i = 0; i < numberOfShapes; i++) {
		area[i] = shapes[i]->calcArea();
	}
	for (int i = 0; i < numberOfShapes; i++) {
		inertiaX[i] = shapes[i]->calcInertiaX();
	}
	for (int i = 0; i < numberOfShapes; i++) {
		inertiaY[i] = shapes[i]->calcInertiaY();
	}

}


Shape* Crosssection::interface() {
	Shape* thisShape = nullptr;
	char input;
	int x;
	int y;
	char den;
	int d;
	int r;
	int base;
	int height;

	cout << "Enter C for circle, R for Rectangle: " << endl;
	output << "Enter C for circle, R for Rectangle: " << endl;
	cin >> input;

	if (input == 'C' || input == 'c') {
		output << "C" << endl;

		cout << "Enter x-coordinate of center: " << endl;
		output << "Enter x-coordinate of center: " << endl;
		cin >> x;

		cout << "Enter y-coordinate of center: " << endl;
		output << "Enter y-coordinate of center: " << endl;
		cin >> y;

		cout << "Enter S for solid, H for hole: " << endl;
		output << "Enter S for solid, H for hole: " << endl;
		cin >> den;

		if (den == 'S' || den == 's') {
			d = 1;
		}

		if (den == 'H' || den == 'h') {
			d = -1;
		}

		cout << "Enter radius: " << endl;
		output << "Enter radius: " << endl;
		cin >> r;

		thisShape = new Circle(x, y, d, r);

		return thisShape;

	}

	else if (input == 'R' || input == 'r') {
		output << "R" << endl;

		cout << "Enter x-coordinate of lower-left corner: " << endl;
		output << "Enter x-coordinate of lower-left corner: " << endl;
		cin >> x;

		cout << "Enter y-coordinate of lower-left corner: " << endl;
		output << "Enter y-coordinate of lower-left corner: " << endl;
		cin >> y;

		cout << "Enter S for solid, H for hole: " << endl;
		output << "Enter S for solid, H for hole: " << endl;
		cin >> den;

		if (den == 'S' || den == 's') {
			d = 1;
		}

		if (den == 'H' || den == 'h') {
			d = -1;
		}

		cout << "Enter base width: " << endl;
		output << "Enter base width: " << endl;
		cin >> base;

		cout << "Enter height: " << endl;
		output << "Enter height: " << endl;
		cin >> height;



		thisShape = new Rectangle(x, y, d, base, height);

		return thisShape;
		
	}

	else {
		cout << "Error: invalid selection" << endl;
		output << "Error: invalid selection" << endl;
	}

	return thisShape;
}

double Crosssection::calcSectionArea() {
	for (int i = 0; i < numberOfShapes; i++) {
		sectionArea += area[i];
	}
	cout << "Section Area is: " << sectionArea << endl;
	return sectionArea;
}

double Crosssection::calcSectionCentroidX() {
	double numerator = 0;
	for (int i = 0; i < numberOfShapes; i++) {
		numerator += (area[i] * centroidX[i]);
	}
	sectionCentroidX = numerator / sectionArea;
	cout << "Section centroid x coordinate is: " << sectionCentroidX << endl;
	return sectionCentroidX;
}

double Crosssection::calcSectionCentroidY() {
	double numerator = 0;
	for (int i = 0; i < numberOfShapes; i++) {
		numerator += (area[i] * centroidY[i]);
	}
	sectionCentroidY = numerator / sectionArea;
	cout << "Section centroid y coordinate is: " << sectionCentroidY << endl;
	return sectionCentroidY;
}

double Crosssection::calcSectionInertiaX() {
	for (int i = 0; i < numberOfShapes; i++) {
		sectionInertiaX += (inertiaX[i] * abs(centroidY[i] - sectionCentroidY));
	}
	cout << "Section Ix: " << sectionInertiaX << endl;
	return sectionInertiaX;
}

double Crosssection::calcSectionInertiaY() {
	for (int i = 0; i < numberOfShapes; i++) {
		sectionInertiaY += (inertiaY[i] * abs(centroidX[i] - sectionCentroidX));
	}
	cout << "Section Iy: " << sectionInertiaY << endl;
	return sectionInertiaY;
}