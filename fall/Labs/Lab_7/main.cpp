#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>

#include "Date.hpp"

using namespace std;

// Get and parse a date string (mm/dd/yyy)
bool getDate(string prompt, int& month, int& day, int& year) { 
	string input, token;
	int mdy[] = {0,0,0};
	cout << prompt << "? ";
	cin.clear(); cin.sync(); 
	getline(cin, input);
	stringstream ss(input);
	int index = 0;
    while(getline(ss, token, '/') && index < 3) {
          istringstream iss(token);
          iss >> mdy[index++];
    }
	month=mdy[0]; day=mdy[1]; year=mdy[2];
	return (input == "") ? false : true;
}
// Get, parse and validate a datestring (mm/dd/yyy)
Date getValidDate(string prompt) {
	int month, day, year;
	bool isValid;
	do {
		getDate(prompt, month, day, year);
		isValid = Date::isValidDate(month, day, year);
		if(isValid == false)
			cout << "The entry is not a valid date" << endl;
	}
	while (isValid == false);
	return Date(month,day,year);
}
// Input option to repeat
bool getOption() {
	char option;
	cout << "Repeat? ";
	cin.clear(); cin.sync(); cin >> option; option=tolower(option);
	while(option!='y' && option!='n') {
		cout << "The entry must be \'y\' or \'n\'. Repeat? ";
		cin.clear(); cin.sync(); cin >> option; option=tolower(option);
	}
	return (option=='y' ? true : false);
}
// Show date comparisons
void showComparisons(Date &mdy1, Date &mdy2) {
	string what;
	what = (mdy1==mdy2) ? "is" : "is not";
	cout << endl << mdy1.toString() << " " << what << " equal to " << mdy2.toString() << endl;
	what = (mdy1>mdy2) ? "is" : "is not";
	cout << mdy1.toString() << " " << what << " greater than " << mdy2.toString() << endl;
	what = (mdy1<mdy2) ? "is" : "is not";
	cout << mdy1.toString() << " " << what << " less than " << mdy2.toString() << endl;
	what = (mdy1>=mdy2) ? "is" : "is not";
	cout << mdy1.toString() << " " << what << " greater than or equal to " << mdy2.toString() << endl;
	what = (mdy1<=mdy2) ? "is" : "is not";
	cout << mdy1.toString() << " " << what << " less than or equal to " << mdy2.toString() << endl << endl;
}
// Main
int main(int argc, char** argv) {

	cout << "Date Class Relational Operator Overloads" << endl;
	cout << "----------------------------------------" << endl;
	do {
		cout << endl;
		Date mdy1 = getValidDate("Date to the left  of the operator");
		Date mdy2 = getValidDate("Date to the right of the operator");
		showComparisons(mdy1,mdy2);
	}
	while(getOption());
	return 0;
}
