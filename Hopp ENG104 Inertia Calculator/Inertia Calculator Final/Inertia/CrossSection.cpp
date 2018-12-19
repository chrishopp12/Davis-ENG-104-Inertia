/*
ENG 104 - Inertia Calculator
Author:  Chris Hopp - 915866326
Version: 12.07.2018

*/

#include "CrossSection.h"
#include "InertiaCalc.h"

#include <fstream>
#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif


extern ofstream output;

using namespace std;


CrossSection::CrossSection(int shapes) {

	numberOfShapes = shapes;
	const int MAX = 100;
	const int MOMENT = 10;  //10kN m  moment to test max normal stress
	
	char input;
	double x;
	double y;
	char density;
	double radius;
	double base;
	double height;

	int den[MAX];
	double centroidX[MAX];
	double centroidY[MAX];
	double area[MAX];
	double inertiaX[MAX];
	double inertiaY[MAX];
	double inertiaXY[MAX];

	double sectionArea = 0;
	double sectionCentroidX = 0;
	double sectionCentroidY = 0;
	double sectionInertiaXY = 0;
	double sectionInertiaX = 0;
	double sectionInertiaY = 0;
	double inertiaMax = 0;
	double inertiaMin = 0;
	double stress = 0;
	




	for (int i = 0; i < numberOfShapes; i++) {

		cout << "Enter C for circle, R for Rectangle: ";				//User input for shape type and location
		output << "Enter C for circle, R for Rectangle: ";
		cin >> input;

		if (input == 'C' || input == 'c') {
			output << " C" << endl;

			cout << "Enter x-coordinate of center: ";
			output << "Enter x-coordinate of center: ";
			cin >> x;
			output << x << endl;

			cout << "Enter y-coordinate of center: ";
			output << "Enter y-coordinate of center: ";
			cin >> y;
			output << y << endl;

			cout << "Enter S for solid, H for hole: ";				//Allows for calculation of negative area and inertia
			output << "Enter S for solid, H for hole: ";
			cin >> density;
			output << density << endl;

			if (density == 'S' || density == 's') {
				den[i] = 1;
			}

			if (density == 'H' || density == 'h') {
				den[i] = -1;
			}

			cout << "Enter radius: ";
			output << "Enter radius: ";
			cin >> radius;
			output << radius << endl;

			centroidX[i] = x;												//Calculates centroid, area, and inertia of individual shapes and stores in an array
			centroidY[i] = y;
			area[i] = (den[i] * pow(radius,2) * M_PI);
			inertiaX[i] = (den[i] * pow(radius,4) * (M_PI / 4.0));
			inertiaY[i] = (den[i] * pow(radius,4) * (M_PI / 4.0));

			cout << "Shape Ix is: " << inertiaX[i] << " cm^4" << endl;
			cout << "Shape Iy is: " << inertiaY[i] << " cm^4" << endl << endl;
			output << "Shape Ix is: " << inertiaX[i] << " cm^4" << endl;
			output << "Shape Iy is: " << inertiaY[i] << " cm^4" << endl << endl;

		}


		else if (input == 'R' || input == 'r') {
			output << "R" << endl;												//Rectangle shape and location

			cout << "Enter x-coordinate of lower-left corner: ";
			output << "Enter x-coordinate of lower-left corner: ";
			cin >> x;
			output << x << endl;

			cout << "Enter y-coordinate of lower-left corner: ";
			output << "Enter y-coordinate of lower-left corner: ";
			cin >> y;
			output << y << endl;

			cout << "Enter S for solid, H for hole: ";
			output << "Enter S for solid, H for hole: ";
			cin >> density;
			output << density << endl;

			if (density == 'S' || density == 's') {
				den[i] = 1;
			}

			if (density == 'H' || density == 'h') {
				den[i] = -1;
			}

			cout << "Enter base width: ";						//User enters base and height of individual shape
			output << "Enter base width: ";
			cin >> base;
			output << base << endl;

			cout << "Enter height: ";
			output << "Enter height: ";
			cin >> height;
			output << height << endl << endl;

			centroidX[i] = ((base / 2.0) + x);							//Calculates centroid, area, and inertia of individual shape
			centroidY[i] = ((height / 2.0) + y);
			area[i] = (den[i] * base * height);
			inertiaX[i] = ((den[i] * base * pow(height, 3))/12.0);
			inertiaY[i] = ((den[i] * height * pow(base,3))/12.0);

			cout << "Shape Ix is: " << inertiaX[i] << " cm^4" << endl;
			cout << "Shape Iy is: " << inertiaY[i] << " cm^4" << endl << endl;
			output << "Shape Ix is: " << inertiaX[i] << " cm^4" << endl;
			output << "Shape Iy is: " << inertiaY[i] << " cm^4" << endl << endl;

		}

		else {
			cout << "Error: invalid selection" << endl;
			output << "Error: invalid selection" << endl;
		}




	}

	for (int i = 0; i < numberOfShapes; i++) {								//Sums area of shapes to determine area of crosssection
		sectionArea += area[i];
	}
	cout << "Section Area is: " << sectionArea << " cm^2" << endl;
	output << "Section Area is: " << sectionArea << " cm^2" << endl;

	double numerator = 0;													//Calculates centroid from shape area and shape centroid distance to axis
	for (int i = 0; i < numberOfShapes; i++) {
		numerator += (area[i] * centroidX[i]);
	}
	sectionCentroidX =(numerator / sectionArea);
	cout << "Section centroid x coordinate is: " << sectionCentroidX << endl;
	output << "Section centroid x coordinate is: " << sectionCentroidX << endl;

	numerator = 0;
	for (int i = 0; i < numberOfShapes; i++) {
		numerator += (area[i] * centroidY[i]);
	}

	sectionCentroidY = (numerator / sectionArea);
	cout << "Section centroid y coordinate is: " << sectionCentroidY << endl;
	output << "Section centroid y coordinate is: " << sectionCentroidY << endl;


	for (int i = 0; i < numberOfShapes; i++) {																		//Calculates product of inertia from shape area and distance to centroid in both x and y directions
		inertiaXY[i] = (area[i] * (centroidX[i] - sectionCentroidX) * (centroidY[i] - sectionCentroidY));
		if (abs(inertiaXY[i]) < .0001) inertiaXY[i] = 0;															//Handles roundoff error for small numbers
	
		cout << "Shape " << (i + 1) << " product of inertia is: " << inertiaXY[i] << " cm^4" << endl;
		output << "Shape " << (i + 1) << " product of inertia is: " << inertiaXY[i] << " cm^4" << endl;
	}

	for (int i = 0; i < numberOfShapes; i++) {																		//Sums shape product of inertia to calculate crosssection product of inertia
		sectionInertiaXY += inertiaXY[i];
	}

	cout << "Section product of inertia is: " << sectionInertiaXY << " cm^4" << endl;
	output << "Section product of inertia is: " << sectionInertiaXY << " cm^4" << endl;

	for (int i = 0; i < numberOfShapes; i++) {																		//Calculates inertia in x and y directions using shape inertia and parallel axis
		sectionInertiaX += (inertiaX[i] + (area[i] * pow(abs(centroidY[i] - sectionCentroidY),2)));
	}
	cout << "Section Ix: " << sectionInertiaX << " cm^4" << endl;
	output << "Section Ix: " << sectionInertiaX << " cm^4" << endl;


	for (int i = 0; i < numberOfShapes; i++) {
		sectionInertiaY += (inertiaY[i] + (area[i] * pow(abs(centroidX[i] - sectionCentroidX),2)));
	}
	cout << "Section Iy: " << sectionInertiaY << " cm^4" << endl;
	output << "Section Iy: " << sectionInertiaY << " cm^4" << endl;

	inertiaMax = ((sectionInertiaX + sectionInertiaY) / 2.0) + (sqrt(pow(((sectionInertiaX - sectionInertiaY) / 2.0), 2) + pow(sectionInertiaXY, 2)));
	inertiaMin = ((sectionInertiaX + sectionInertiaY) / 2.0) - (sqrt(pow(((sectionInertiaX - sectionInertiaY) / 2.0), 2) + pow(sectionInertiaXY, 2)));

	cout << "Inertia Max: " << inertiaMax << " cm^4" << endl;
	cout << "Inertia Min: " << inertiaMin << " cm^4" << endl;
	output << "Inertia Max: " << inertiaMax << " cm^4" << endl;
	output << "Inertia Min: " << inertiaMin << " cm^4" << endl;

	stress = (1000*((sectionCentroidY * MOMENT) / (sectionInertiaX)));		//This only works for shapes at x=0 that have a centroid at a distance equal or further from the x axis than the top of the shape using units specific to this project 
	cout << "Max normal stress is: " << stress << " MPa" << endl << endl;
	output << "Max normal stress is: " << stress << " MPa" << endl << endl;

}





