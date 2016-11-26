/* Lab 6 - Extension of Lab 5 */
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
		
		// Operator overloads
//		bool operator> (Date &rhs);
//		bool operator<=(Date &rhs);
//		bool operator>=(Date &rhs);
};

static bool isValidDate(int m, int d, int y);
static bool isLeapYear(int y);

bool operator==(const Date& lhs, const Date& rhs);
bool operator< (const Date& lhs, const Date& rhs);
bool operator> (const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs); 
bool operator>=(const Date& lhs, const Date& rhs);
#endif

