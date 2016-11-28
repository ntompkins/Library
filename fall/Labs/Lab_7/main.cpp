// Lab 7 Incremement/Decrement Operator Overloading
// Nathan Tompkins

/* 

	Professor,
	Once again my program refused to work while in separate files,
	so I combined them into a single main.cpp in order to submit a
	working program. The end result does meet all criteria except
	for being in separate files.
	- Nathan
	
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

enum DateFormat {SHORT_DATE, LONG_DATE};

class Date {
	private:
		// Member variables
		int month,day,year;
		// Member functions
		void setDefaultDate();
	public:
		// Constructors
		Date() {
			setDefaultDate();
		};
		Date(int m,int d,int y) {
			if(isValidDate(m,d,y)==false)
				setDefaultDate();
			else {
				month=m; day=d; year=y;
			}
		}
		// Destructors
		~Date() {}
		// Getters
		int getMonth() {return month;}
		int getDay() {return day;}
		int getYear() {return year;}
		int getDaysInMonth(int);
		// Setter function prototypes
		bool setMonth(int m);
		bool setDay(int d);
		bool setYear(int y);
		// Member function prototypes
		bool isDefaultDate();
		bool setDate(int m,int d,int y);
		string toString(DateFormat df = SHORT_DATE);
		
		static bool isValidDate(int m, int d, int y);
		static bool isLeapYear(int y);
		
		/* Lab 7 */
		// Prefix increment
		Date& operator++();
		// Postfix increment
		Date operator++(int);
		// Prefix decrement
		Date& operator--();
		// Postfix decrement
		Date operator--(int);
};
// Prefix increment
Date& Date::operator++() {
	if (this->isValidDate(this->getMonth(), this->getDay() + 1, this->getYear()))
		this->setDay(this->getDay() + 1);
	else	
		this->isValidDate(this->getMonth() + 1, 1, this->getYear()) ? 
			this->setDate(this->getMonth() + 1, 1, this->getYear()) :
			this->setDate(1, 1, this->getYear() + 1);
	return *this;
}

int Date::getDaysInMonth(int mon) {
	if(mon != 2) {
		const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		return daysInMonth[mon - 1];
	} else return this->isLeapYear(this->getYear()) ? 29 : 28;	 
}
// Postfix increment
Date Date::operator++(int) {
	Date temp = *this;
	++*this;
	return temp;
}
// Prefix decrement
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
// Postfix decrement
Date Date::operator--(int) {
	Date temp = *this;
	--*this;
	return temp;
}

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

/*
*** MAIN.CPP ***
*/

bool getDate(int& month, int& day, int& year, string prompt) { 
	while (month!=0 && day!=0 && year!=0) {
		string input, token;
		int mdy[] = {1,1,1};
		
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
	cout << "Date manipulator.\nEnter 0/0/0 to quit.\n";
	int month, day, year;
	while(getDate(month, day, year, "Enter a date: ")) {
			if(Date::isValidDate(month, day, year)) {
				Date usrDate(month, day, year);
				cout << usrDate.toString() << endl;
				--usrDate;
				cout << usrDate.toString() << endl;
				usrDate--;
				cout << usrDate.toString() << endl;
				++usrDate;
				cout << usrDate.toString() << endl;
				usrDate++;
				cout << usrDate.toString() << endl;
			}
	}
	return 0;
}

