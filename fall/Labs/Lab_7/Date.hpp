/*
Lab6 - Date Class Relational Operator Overloads
------------------------------------------------
Overload the following relational operators in the Date class developed in 
Lab5 to allow comparisions between Date class objects:

	==	Equal to
	<	Less than
	>	Greater than
	<=	Less than or equal to
	>=	Greater than or equal to

For example:
 
	Date mdy1(11,15,2016), mdy2(11,16,2016);
	if(mdy1 > mdy2)
		cout << mdy1.toString() << " is greater than " << mdy2.toString();
	
Develop the overloads as stand-alone (rather than member function) operators.

Write a program that demonstrates each of the Date class operator overrides. 
The program should consist of a loop that provides the following functionality:
    1. Prompt the user to enter month, day, and year for the date to the
       left of the operator.
    2. Prompt the user to enter month, day, and year for the date to the
       right of the operator
    3. Create the two date objects.
    4. Perform the 5 comparisions between the two date objects and display 
       the result of each comparision.
    5. Prompt the user for an option to repeat. If affirmative, repeat
       steps 1-5, otherwise terminate the program.

Submit the answer as a zip file containing the date.hpp, date.cpp, and main.cpp 
files.
*/

#ifndef DATE_H
#define DATE_H

#include <string>
	
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
		// Operator overloads (relational)
		friend bool operator<(Date a, Date b);
		friend bool operator>(Date a, Date b);
		friend bool operator==(Date a, Date b);
		friend bool operator<=(Date a, Date b);
		friend bool operator>=(Date a, Date b);
};

static bool isValidDate(int m, int d, int y);
static bool isLeapYear(int y);

#endif

