#include <iostream>
#include <string>
using namespace std;

enum DateFormat { SHORT_DATE, LONG_DATE };
const int DEFAULT_MONTH = 1, DEFAULT_DAY = 1, DEFAULT_YEAR = 1900;

class Date {
	private:
		// Member variables
		int month, day, year;
		// Member functions
		void setDefaultDate();
	public:
		// Constructors
		Date() { setDefaultDate(); }
		Date(int m, int d, int y) { 
			if (isValidDate(m,d,y)) setDate(m, d, y); else setDefaultDate();
		}
		// Private Getters
		int getMonth() 	{ return month; }
		int getDay() 	{ return day;	}
		int getYear() 	{ return year;	}
		
		// Setter function prototypes
		bool setMonth(int m);
		bool setDay	 (int d);
		bool setYear (int y);
		
		// Member function prototypes
		int getDaysInMonth(int);
		
		bool setDate(int m, int d, int y);
		bool isDefaultDate();
		static bool isValidDate(int m, int d, int y);
	 	static bool isLeapYear(int y);
		string toString(DateFormat df = SHORT_DATE);
		
		// Unary Operator Overloads - Lab 7
		Date& operator++();
		Date& operator--();
		Date operator++(int);
		Date operator--(int);
};

