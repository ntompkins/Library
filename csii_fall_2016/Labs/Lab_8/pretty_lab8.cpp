#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

const int daysInMonth[] = 
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date {
	// Variables
	int year, month, day;
	
	public: 
		// Constructors
		Date() { setDefault(); }
		Date(int y, int m, int d)
		{ setDate(y, m, d); }
		
		// Accessors
		int getYear()	{ return year; }
		int getMonth(){ return month;}
		int getDay()	{ return day;	 }
		
		int getDays() { 
			return (getMonth() == 2) ? (isLeapYear(getYear()) ? 29 : 28) : (daysInMonth[this->month]);
		}
		// Mutators
		void setYear (int y) { year  = ( 0 < y )					? y : 2000; }
		void setMonth(int m) { month = ( 0 < m && m < 13) ? m : 1;		}
		void setDay	 (int d) { day	 = ( 0 < d && d < getDays()) ? d : 1; }

		// Methods
			// Value Initialisers
		bool setDate(int y, int m, int d) {
			setYear(y); setMonth(m); setDay(d); 
			return true;
		}
		bool setDefault() {
			setDate(1,1,2000);
		}
		bool isLeapYear(int y) {
			return (y % 100 == 0 && y % 400 == 0) || y % 4 == 0 ? true : false; 
		}
			// Operators
			// 
		
};

int main() {
	return 0;
}
