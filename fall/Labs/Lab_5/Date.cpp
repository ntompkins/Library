#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

/* Default Constructor */
Date::Date() { 
    setDefaultDate(); 
}

/* Overloaded Constructor */
Date::Date(int m, int d, int y) { 
    setDate(m,d,y); 
}

/* Getters */
int Date::getYear() 	{ return year;  }
int Date::getMonth() 	{ return month; }
int Date::getDay() 	    { return day;   }

/* Default Setters */
void Date::setYear (int y) { 
    if( isValidYear(y) ) year = y; else setDefaultDate();
}
void Date::setMonth(int m) { 
    if( isValidMonth(m) ) month= m; else setDefaultDate();
}
void Date::setDay  (int d) {
    if( isValidDay(d) ) day  = d; else setDefaultDate();
}

/* Custom Setters */
void Date::setDate(int m, int d, int y) { 
    setYear(y); setMonth(m); setDay(d); 
}
void Date::setDefaultDate() { 
    setYear(1990); setMonth(1); setDay(1); 
}

/* Date Validation */
bool Date::isValidYear (int y) { 
    if(y >= 1) return true; 
    else return false;
}
bool Date::isValidMonth(int m) { 
    if(m >= 1 && m <= 12) return true; 
    else return false; 
}
bool Date::isValidDay  (int d) { 
    if(d >= 1 && d <= daysInMonth( getMonth() )) return true; 
    else return false; 
}
bool Date::isValidDate (int m, int d, int y) { 
    if( isValidYear(y) && isValidMonth(m) && isValidDay(d) ) return true; 
    else return false;
}
/* Checks if year is a leap year */
bool Date::isLeapYear(int y) {
	if ( y % 100 == 0) {
		if ( y % 400 == 0 ) return true; else return false;
	} else {
		if ( y % 4 == 0) 	return true; else return false;
	}
}

/* Custom Functions */
int Date::daysInMonth(int m) {
	if(m != 2) {
		int calendar[12] = { 31, 00, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return calendar[m - 1];
	} else {
		/* If month is February, checks if year is leap year */
		if(isLeapYear(getYear())) return 29;
		else return 28;
	}
}
void Date::display() {
	cout << "Month: " << month << " Day: " << day << " Year: " << year << endl;
}

/* Create enumerated type */
enum DateFormat { SHORT_FORM, LONG_FORM };
