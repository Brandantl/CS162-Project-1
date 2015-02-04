//multiplicationTable.cpp
//Written By: Brandan Tyler Lasley
//Project 01: CS 162 Multiplication Table
//Date: 1 January 2014 04:47
//Sources: None
// This prints out a multiplication table based on what the user defines.

/*
 Known Issues & Limitations:
 * If you click the red "X" at the top right of the program, it ceases execution, same issue with ALT + F4.
 * I dont know of any issues with it, it seems error tolerant.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

bool validate(int number);

int main() {

	// Declaring Varibles
	string input;  // A input varible to prevent non int errors.
	int    number = 0;// The number the user choose
	int    width = 5; // Width/spacing of the table

	do {
		while (true) {
		   cout << "Please enter an integer between 4-12: ";
		   // Get the entire line for processing, spaces and everthing!
		   // Incase of a user entering '5, 6, 7' only 5 will be processed!
		   getline(cin, input);
		   // Converts type STRING to INT
		   stringstream myStream(input);
		   if (myStream >> number) {
			 break;
		   }
		}
	} while (!validate(number)); // Check if number is < 4 but not > 12!

	// formatting
	cout << endl << endl <<  "     ";

	// Generate Table

	// Generate the first row
	for (int i = 0; i <= number; i++) {
		cout << left << setw(width) << i;
	}
	cout << endl;

	// Generate the rest of the rows and columns.
	for (int r = 0; r <= number; r++) {
	// Prints out first number (column) of the row
		cout << left << setw(width) << r;
        for(int c = 0; c <= number; c++) {
			// Prints out the rest of the columns and multiplys it by C * R (the first row)
			cout << left << setw(width) << c * r;
        }
	// formatting
	cout << endl;
	}

	// Pause and exit
	getchar();
	getchar();
	return 0;
}

bool validate(int number) {
	// I dont know how I can explain this, if number is not less than 4 but not greater than 12 return true, else false.
	if (!(number < 4)) {
		if (!(number > 12)) {
			return true;
		}
	}
	return false;
}
