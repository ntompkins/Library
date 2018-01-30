#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include "date.hpp"

using namespace std;

bool getDate(int& month, int& day, int& year, string prompt) { 
	string input, token;
	int mdy[] = {0,0,0};
	
	cout << prompt;
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
bool operator==(Date& lhs, Date &rhs) {
    // Checks year
    return ( 
		(lhs.getYear()  == rhs.getYear())  && 
		(lhs.getMonth() == rhs.getMonth()) && 
		(lhs.getDay()   == rhs.getDay()) 
		) ? true : false;
}
bool operator<(Date& lhs, Date& rhs) {
	// Less than
	bool result = false;
	if(lhs.getYear() < rhs.getYear())  		return true;
	else if(lhs.getMonth()< rhs.getMonth()) return true;
	else if(lhs.getDay()  < rhs.getDay())   return true;
	else return false;
	
}
bool operator>(Date& lhs, Date& rhs) {
	return operator<(rhs, lhs);
}
bool operator<=(Date& lhs, Date& rhs) {
	return !operator> (lhs, rhs);
}
bool operator>=(Date& lhs, Date& rhs) {
	return !operator< (lhs, rhs);
}
string verb(bool v) {
	return v == true ? "is" : "is not";
}

// Main
int main(int argc, char** argv) {
	cout << "Lab 6 - Date Comparison" << endl;
	cout << "------------------" << endl;
	
	int month=0, day=0, year=0;
	Date leftSide, rightSide;
	while(getDate(month, day, year, "Enter left hand date: ")) {
		
		if(Date::isValidDate(month, day, year)) {
			int rMonth=0, rDay=0, rYear=0;
			while(getDate(rMonth, rDay, rYear, "\nEnter right hand date: ")) {
				
				if(Date::isValidDate(rMonth, rDay, rYear)) {
					Date leftSide(month, day, year), 
						 rightSide(rMonth, rDay, rYear);
					// ==
					cout << leftSide.toString() << ' ' << verb(leftSide == rightSide) << " equal to " << rightSide.toString() << endl;
					// <
					cout << leftSide.toString() << ' ' << verb(leftSide < rightSide) << " less than " << rightSide.toString() << endl;
					// >
					cout << leftSide.toString() << ' ' << verb(leftSide > rightSide) << " greater than " << rightSide.toString() << endl;
					// <=
					cout << leftSide.toString() << ' ' << verb(leftSide <= rightSide) << " less than or equal to " << rightSide.toString() << endl;
					// >=
					cout << leftSide.toString() << ' ' << verb(leftSide >= rightSide) << " greater than or equal to " << rightSide.toString() << endl;
					
					cout << "\nContinue? (y/n)";
					char response; cin >> response;
					response = tolower(response);
					if(response == 'y') { continue; }
					else { return 0; }
				}
			}	
		}
	}
	return 0;
}

