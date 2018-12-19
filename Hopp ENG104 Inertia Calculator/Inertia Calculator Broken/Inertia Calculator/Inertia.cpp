/*
ENG 104 - Inertia Calculator
Author:  Chris Hopp - 915866326
Version: 11.10.2018

*/


# include <iostream>
#include <fstream>
#include "Inertia.h"
#include "Crosssection.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

ofstream output;

int main(){
	output.open("output.txt");
	
	char prompt;

	cout << "Would you like to enter another cross section? Y / N" << endl << endl;
	output << "Would you like to enter another cross section? Y / N" << endl << endl;

	cin >> prompt; cin.ignore();

	while (prompt != 'N' || prompt != 'n') {

		if (prompt == 'Y' || prompt == 'y') {
			output << "Y" << endl;


			Crosssection c;
			cout << c.calcSectionArea();

			
			return 0;
		}

		else if (prompt == 'N' || prompt == 'n'){
			output << "N" << endl << endl;
			return 0;

		}

		else {
			cout << "Invalid entry: " << endl << endl;
			output << "Inavalid entry: " << endl << endl;

			cout << "Would you like to enter another cross section? Y / N" << endl << endl;
			output << "Would you like to enter another cross section? Y / N" << endl << endl;
			cin >> prompt; cin.ignore();
		}

	}
	

}