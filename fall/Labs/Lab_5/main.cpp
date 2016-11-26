/* 
Lab 5: Date & Leap Year Calculator 
Nathan Tompkins | 11-11-16

Overload the following relational operators in 
the Date class developed in Lab5 to allow comp
arison between Date class objects:

     == Equal to
       < Less than
       > Greater than
     <= Less than or equal to
     >= Greater than or equal to

For example:
 
Date mdy1(11,15,2016), mdy2(11,16,2016);
if(mdy1 > mdy2)
    cout << mdy1.toString() << " is greater than " << mdy2.toString();
 
Develop the overloads as stand-alone (rather 
than member function) operators.

Write a program that demonstrates each of the Date 
class operator overrides. The program should consist 
of a loop that provides the following functionality:

1. Prompt the user to enter month, day, and year for the date to the left of the operator.
2. Prompt the user to enter month, day, and year for the date to the right of the operator.
3. Create the two Date objects.
4. Perform the 5 comparisons between the two Date objects and display the result of each comparison.
5. Prompt the user for an option to repeat. If affirmative, repeat steps 1-5, otherwise terminate the program.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Date {
  private:
    int year, month, day;
  
  public:
    Date() { 
        setDefaultDate(); 
    }
    
    /* Overloaded Constructor */
    Date(int m, int d, int y) { 
        setDate(m,d,y); 
    }
    
    /* Getters */
    int getYear() 	{ return year;  }
    int getMonth() 	{ return month; }
    int getDay() 	{ return day;   }
    
    /* Default Setters */
    void setYear (int y) { 
        if( isValidYear(y) ) year = y; else setDefaultDate();
    }
    void setMonth(int m) { 
        if( isValidMonth(m) ) month= m; else setDefaultDate();
    }
    void setDay  (int d) {
        if( isValidDay(d) ) day  = d; else setDefaultDate();
    }
    
    /* Custom Setters */
    void setDate(int m, int d, int y) { 
        setYear(y); setMonth(m); setDay(d); 
    }
    void setDefaultDate() { 
        setYear(1990); setMonth(1); setDay(1); 
    }
    
    /* Date Validation */
    bool isValidYear (int y) { 
        if(y >= 1) return true; 
        else return false;
    }
    bool isValidMonth(int m) { 
        if(m >= 1 && m <= 12) return true; 
        else return false; 
    }
    bool isValidDay  (int d) { 
        if(d >= 1 && d <= daysInMonth( getMonth() )) return true; 
        else return false; 
    }
    bool isValidDate (int m, int d, int y) { 
        if( isValidYear(y) && isValidMonth(m) && isValidDay(d) ) return true; 
        else return false;
    }
    /* Checks if year is a leap year */
    bool isLeapYear(int y) {
    	if ( y % 100 == 0) {
    		if ( y % 400 == 0 ) return true; else return false;
    	} else {
    		if ( y % 4 == 0) 	return true; else return false;
    	}
    }
    
    /* Custom Functions */
    int daysInMonth(int m) {
    	if(m != 2) {
    		int calendar[12] = { 31, 00, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    		return calendar[m - 1];
    	} else {
    		/* If month is February, checks if year is leap year */
    		if(isLeapYear(getYear())) return 29;
    		else return 28;
    	}
    }
    
    /* Create enumerated type */
    enum DateFormat { SHORT_FORM, LONG_FORM };
    
    string toString(DateFormat df) {
    	if (df == SHORT_FORM) {
    		return to_string(month) + '/' + to_string(day) + '/' + to_string(year);
    	} else {
    		string monthNames[12] = {"January","February","March",
    		                         "April","May","June",
    		                         "July","August","September",
    		                         "October","November","December"};
    		return monthNames[getMonth() - 1] + ", " + to_string(getDay()) + ' ' + to_string(year);
    	}
    }
    enum DateType { YEAR, MONTH, DAY };
    int getInput(string prompt, string err, DateType value, Date usrDate) {
        bool invalid = true;
           
            while(invalid) {
                cout << prompt;
                int usrIn=0; cin >> usrIn;
            
                // Convert character to upper for switch
                // value = toupper(value);
                switch(value) {
                    case YEAR:
                        if(usrDate.isValidYear(usrIn)) {
                            return usrIn;
                        }
                        break;
                    case MONTH:
                        if(usrDate.isValidMonth(usrIn)) {
                            usrDate.setMonth(usrIn);
                            invalid = false;
                        }
                        break;
                    case DAY:
                        if(usrDate.isValidDay(usrIn)) {
                            usrDate.setMonth(usrIn);
                            invalid = false;
                        }
                        break;
                    default:
                        usrDate.setDefaultDate();
                        break;
                }
        }
    }
    
    /* Lab 6 - Overloaded Operators */
    const bool operator==(Date &rhs) {
    	// Checks year
        return ( 
				(this->year  == rhs.year)  && 
				(this->month == rhs.month) && 
				(this->day   == rhs.day) 
				) ? true : false;
    }
    const bool operator!=(Date &rhs) {
    	return !operator==(rhs);
	}
    
};
int getInput(string prompt, string err, char value, Date usrDate) {
        int usrIn=1;
        while(usrIn != 0) {
            cout << prompt; cin >> usrIn;
               // Convert character to upper for switch
                value = toupper(value);
                switch(value) {
                    case 'Y':
                        if(usrDate.isValidYear(usrIn))
                            return usrIn;
                        else cout << err;
                        break;
                    case 'M':
                        if(usrDate.isValidMonth(usrIn))
                            return usrIn;
                        else cout << err;
                        break;
                    case 'D':
                        if(usrDate.isValidDay(usrIn))
                            return usrIn;
                        else cout << err;
                        break;
                    default:
                        usrDate.setDefaultDate();
                        break;
                    }
        }
}

void display(Date date) {
    cout << endl << "Short Date: " << date.toString(Date::SHORT_FORM);
    cout << endl << "Long Date: "  << date.toString(Date::LONG_FORM) << endl;
}

int main() {
    cout << "Date Class Program (Enter 0 to quit)\n";
    Date usrDate;
    
    bool running = true;
    
	while(running) {
	    int usrY = getInput("Enter year: ","Invalid input.\n\n",'Y',usrDate);
	    if(usrY == 0) break;
	    
	    int usrM = getInput("Enter month: ","Invalid input.\n\n",'M',usrDate);
	    if(usrM == 0) break;
	    
	    int usrD = getInput("Enter day: ","Invalid input.\n\n",'D',usrDate);
	    if(usrD == 0) break;
	    
	    usrDate.setDate(usrM, usrD, usrY);
	    
	    Date customDate1(3, 16, 1876);
	    Date customDate2;
	    customDate2.setDate(2, 29, 2000);
	    
	    display(usrDate);
	    display(customDate1);
	    display(customDate2);
	}
	return 0;
}
