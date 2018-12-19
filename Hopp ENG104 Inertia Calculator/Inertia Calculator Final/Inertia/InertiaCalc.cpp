/*
ENG 104 - Inertia Calculator
Author:  Chris Hopp - 915866326
Version: 12.07.2018

*/

#include "InertiaCalc.h"
#include "CrossSection.h"
#include <iostream>
#include <fstream>

using namespace std;

ofstream output;


int main() {
	output.open("output.txt");

	int num = 0;

	cout << "Enter number of cross sections: ";						//User input for number of crosssections to be entered
	output << "Enter number of cross sections: ";
	cin >> num;
	output << num << endl;

	for (int i = 0; i < num; ++i) {

		int number = 0;

		cout << "Enter number of shapes: ";							//User input for number of shapes that make crosssection
		output << "Enter number of shapes: ";
		cin >> number;
		output << number << endl;


		CrossSection cs(number);									//Creates an object for the crosssection consisting of shapes

	}


}




