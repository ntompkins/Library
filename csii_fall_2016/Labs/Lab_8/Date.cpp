#include <iostream>
#include <string>
#include "Date.hpp"

using namespace std;

/* Function Definitions */
bool Date::isValidDate(int m, int d, int y) {
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
bool Date::isDefaultDate() {
	return (month==DEFAULT_MONTH && day==DEFAULT_DAY && year==DEFAULT_YEAR) ? true : false;
}
bool Date::isLeapYear(int y) {
	return (y % 100 == 0 && y % 400 == 0) || y % 4 == 0 ? true : false; 
}
int Date::getDaysInMonth(int mon) {
	if(mon != 2) {
		const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		return daysInMonth[mon - 1];
	} else return this->isLeapYear(this->getYear()) ? 29 : 28;	 
}

void Date::setDefaultDate() {
	month=DEFAULT_MONTH; day=DEFAULT_DAY; year=DEFAULT_YEAR;
}
bool Date::setDate	(int m,int d,int y) {
	bool result = false;
	if(isValidDate(m,d,y)) {
		month=m; day=d; year=y;
		result=true;
	}
	return result;
}
bool Date::setMonth	(int m) {
	bool result=false;
	if(Date::isValidDate(m, day, year)) {
		month = m;
		result=true;
	}
	return result;
}
bool Date::setDay	(int d) {
	bool result=false;
	if(Date::isValidDate(month, d, year)) {
		day = d;
		result=true;
	}
	return result;
}
bool Date::setYear	(int y) {
	bool result=false;
	if(Date::isValidDate(month, day, y)) {
		year = y;
		result=true;
	}
	return result;
}

bool operator==(Date& lhs, Date& rhs) {
    return ((lhs.getYear()  == rhs.getYear())  && 
			(lhs.getMonth() == rhs.getMonth()) && 
			(lhs.getDay()   == rhs.getDay()) ) ? true : false;
}
bool operator< (Date& lhs, Date& rhs) {
	// Less than
	if(lhs.getYear() < rhs.getYear())  		return true;
	else if(lhs.getMonth()< rhs.getMonth()) return true;
	else if(lhs.getDay()  < rhs.getDay())   return true;
	else return false;
	
}
bool operator> (Date& lhs, Date& rhs) {
	return operator<(rhs, lhs);
}
bool operator<=(Date& lhs, Date& rhs) {
	return !operator> (lhs, rhs);
}
bool operator>=(Date& lhs, Date& rhs) {
	return !operator< (lhs, rhs);
}

Date& Date::operator++() {
	if (this->isValidDate(this->getMonth(), this->getDay() + 1, this->getYear()))
		this->setDay(this->getDay() + 1);
	else	
		this->isValidDate(this->getMonth() + 1, 1, this->getYear()) ? 
			this->setDate(this->getMonth() + 1, 1, this->getYear()) :
			this->setDate(1, 1, this->getYear() + 1);
	return *this;
}
Date  Date::operator++(int) {
	Date temp = *this;
	++*this;
	return temp;
}
Date& Date::operator--() {
	// If there are enough days left in the month
	if (this->getDay() - 1 > 0 ) // Go down a day
		this->setDay(getDay() - 1);
	else {
		// If going down a month is valid
		if(this->getMonth() - 1 > 0) {
			// Set the month back and get the max number of days in that month
			this->setDate(this->getMonth() - 1, getDaysInMonth(this->getMonth()), getYear());
		} else {
			// Else go back a year to Dec 31
			this->setDate(12, 31, this->getYear() - 1);
		}
	}
	return *this;
}
Date  Date::operator--(int) {
	Date temp = *this;
	--*this;
	return temp;
}

string Date::toString(DateFormat df) {
	const string monthName[] = {"January", "February", "March", "April", "May", "June","July", 
								"August", "September", "October", "November", "December"};
	string result = "";
	switch(df) {
		case SHORT_DATE:
			result = to_string(month) + '/' + to_string(day) + '/' + to_string(year);
			break;
		case LONG_DATE:
			result = monthName[month - 1] + ' ' + to_string(day) + ", " + to_string(year);
			break;
		default:
			break;
	}
	return result;
}
// bool getDate(int& month, int& day, int& year, string prompt) { 
// 	while (month!=0 && day!=0 && year!=0) {
// 		string input, token;
// 		int mdy[] = {1,1,1};
		
// 		cout << prompt;
// 		getline(cin, input);
		
// 		stringstream ss(input);
// 		int index = 0;
// 	    while(getline(ss, token, '/') && index < 3) {
// 	          istringstream iss(token);
// 	          iss >> mdy[index++];
// 	    }
// 		month=mdy[0]; day=mdy[1]; year=mdy[2];
// 		return (input == "") ? false : true;
// 	}
// }
