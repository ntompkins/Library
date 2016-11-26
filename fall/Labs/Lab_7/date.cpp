#include <string>
#include "date.hpp"

using namespace std;

const int DEFAULT_MONTH = 1, DEFAULT_DAY = 1, DEFAULT_YEAR = 1900;

// Set date
bool Date::setDate(int m,int d,int y) {
	bool result = false;
	if(isValidDate(m,d,y)) {
		month=m; day=d; year=y;
		result=true;
	}
	return result;
}
// Set default date
void Date::setDefaultDate() {
	month=DEFAULT_MONTH; day=DEFAULT_DAY; year=DEFAULT_YEAR;
}

// Setter functions
bool Date::setMonth(int m) {
	bool result=false;
	if(Date::isValidDate(m, day, year)) {
		month = m;
		result=true;
	}
	return result;
}
bool Date::setDay(int d) {
	bool result=false;
	if(Date::isValidDate(month, d, year)) {
		day = d;
		result=true;
	}
	return result;
}
bool Date::setYear(int y) {
	bool result=false;
	if(Date::isValidDate(month, day, y)) {
		year = y;
		result=true;
	}
	return result;
}
// Date validation
bool Date::isValidDate(int m,int d,int y) {
	const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool result=false;
	if(m>0 && m <13) {
		if(y>0) {
			int maxDay=daysInMonth[m-1];
			if(m==2 && isLeapYear(y)==true) maxDay++;
			if(d>0 && d<=maxDay)
				result=true;
		}
	}
	return result;
} 
// Check for default date
bool Date::isDefaultDate() {
	bool result = false;
	return (month==DEFAULT_MONTH && day==DEFAULT_DAY && year==DEFAULT_YEAR) ? true : false;
}
// Determine if leap year
bool Date::isLeapYear(int y) {
	bool result=false;
	if((y%100)==0) {
		if((y%400)==0)
			result=true;
	}
	else if((y%4)==0)
		result = true;
	return result;
}
// Format date (mm/dd/yyyy)
string Date::toString(DateFormat df) {
	const string monthName[] = {"January", "February", "March", "April", "May", "June","July", 
								"August", "September", "October", "November", "December"};
	string result = "";
	switch(df) {
		case SHORT_DATE:
			result = to_string(month)+"/" + to_string(day) + "/" + to_string(year);
			break;
		case LONG_DATE:
			result = monthName[month-1] + " " + to_string(day)+", " + to_string(year);
			break;
		default:
			break;
	}
	return result;
}

