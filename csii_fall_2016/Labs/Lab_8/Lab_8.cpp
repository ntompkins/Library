/* Nathan Tompkins - Lab 8 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

enum DateFormat { SHORT_DATE, LONG_DATE };
const int DEFAULT_MONTH = 1, DEFAULT_DAY = 1, DEFAULT_YEAR = 1900;
const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date {
	private:
		// Member variables
		int month, day, year;
		// Member functions
		void setDefaultDate();
	public:
		// Constructors
		Date() { setDefaultDate(); }
		Date(int m, int d, int y) 
		{ 
			if (isValidDate(m,d,y)) 
			    setDate(m, d, y); 
			else setDefaultDate();
		}
		// Date(int dayOfYear, int year) 
		// {
		//     if (dayOfYear <= getDaysInYear(year))
		//     {
		//     	cout << "Constructing\n";
		//     	int feb = 28;
		//     	if (isLeapYear(year)) feb = 29;
		//     	/* January */
		//     	if (dayOfYear <= 31) 
		//     	{
		//     		setDate(1, dayOfYear, year);
		//     	}
		//     	/* February */
		//     	else if (dayOfYear <= feb + 31)
		//     	{
		//     		setDate(2, dayOfYear - 31, year);
		//     	}
		//     	else {
		//     		cout << "All other months.\n";
		//     		int daysPast = 31 + feb;
		//     		int m = 0;
		//     		int daysRemaining = dayOfYear - daysPast;
		//     		for (int m = 0; m < 12; m++ ) // while (dayOfYear - getDaysInMonth(m++) >= daysPast) 
		//     		{
		//     			cout << "Days in " << m << "= " << getDaysInMonth(m) << endl;
		//     			daysPast += getDaysInMonth(m);
		    		
		//     			daysRemaining = dayOfYear - daysPast;
		//     			cout << "Month " << m << " Remaining = " << daysRemaining << " Past = " << daysPast << endl;
		    		
		//     			setDate(m + 2, getDaysInMonth(m), year);
		//     		}
		    		
		    		
		//     	}
		//     }
		//     else 
		//     {
		//     	setDefaultDate();
		//     }
		// }
		// Private Getters
		int getMonth() 	{ return month; }
		int getDay() 	{ return day;	}
		int getYear() 	{ return year;	}
		
		// Setter function prototypes
		bool setMonth(int m);
		bool setDay	 (int d);
		bool setYear (int y);
		
		// Member function prototypes
		bool setDate(int m, int d, int y);
		bool isDefaultDate();
		int getDaysInMonth(int);
		int getDayOfYear();
		
		// Global functions
		static int getDaysInYear(int);
		static bool isValidDate(int m, int d, int y);
	 	static bool isLeapYear(int y);
	 	
	 	// Output
		string toString(DateFormat df = SHORT_DATE);
		
		// Unary Operator Overloads - Lab 7
		Date& operator++();
		Date& operator--();
		Date  operator++(int);
		Date  operator--(int);
};

/* Function Definitions */
bool Date::isValidDate(int m, int d, int y) {
	bool result=false;
	if( m > 0 && m < 13 ) {
		if( y > 0 ) {
			int maxDay=daysInMonth[m - 1];
			if( m == 2 && isLeapYear(y)) 
			    maxDay++;
			if( d > 0 && d <= maxDay)
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
		return daysInMonth[mon - 1];
	} else return this->isLeapYear(this->getYear()) ? 29 : 28;	 
}
int Date::getDaysInYear(int year) {
    return isLeapYear(year) ? 366 : 365;
}
int Date::getDayOfYear() {
    switch(this->getMonth()) {
        case 1:
            return this->getDay();
            break;
        case 2:
            return this->getDay() + 31;
            break;
        default:
            int totalDays = isLeapYear(this->year) ? 60 : 59;
            for (int pre = 3; pre < this->month; pre++) {
                totalDays += getDaysInMonth(pre);
            }
            return totalDays + this->day;
            break;
    }
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

int main() { 
	int mdy[] = { 1, 1, 1 };
	cout << "Day Number Calculator\nEnter 0/0/0 to quit.\n";
	while ((mdy[0] && mdy[1] && mdy[2]) != 0) {
	    
	    string input="", token="";
	    cout << "Enter a date: ";
        
        getline(cin, input);
        stringstream ss(input);
        
        int index = 0;
        while(getline(ss, token, '/') && index < 3) {
            stringstream ss(token);
            ss >> mdy[index++];
        }
        
        Date usrDate;
	    usrDate.setDate(mdy[0], mdy[1], mdy[2]);
	    cout << usrDate.getDayOfYear() << endl;
	}
	
	return 0;
}

