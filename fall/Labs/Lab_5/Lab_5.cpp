#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Date {
    private:
        /* Base variables */
        int month=0, day=0, year=0;
        
    public:
        /* Constructors */
        Date() { setDefaultDate(); }
        Date(int m, int d, int y);
    
        /* Getters */
        int getMonth()  { return month; }
        int getDay  ()  { return day;   }
        int getYear ()  { return year;  }
        
        /* Setters */
        void setMonth(int m);
        void setDay  (int d);
        void setYear (int y);
        bool setDate (int month, int day, int year);
        bool setDefaultDate();
        
        /* Special Functions */
        bool isValidDate(int m, int d, int y);
        
        /* Leap Year Calculator */
        int getDaysOfMonth(int m);
        void display();
};

// Overloaded Constructor
Date::Date(int m, int d, int y) { 
    isValidDate(m,d,y) ? setDate(m,d,y) : setDefaultDate();
}

// Setters
void Date::setMonth(int m) { 
    if(( 1 <= m ) && ( m <= 12 )) { month = m; } 
    else { setDefaultDate(); } 
}
void Date::setDay(int d) { 
    if(( 1 <= d ) && ( d <= getDaysOfMonth(month))) { day = d; } 
    else { setDefaultDate(); }
}

void Date::setYear(int y) {
    1 <= y ? year = y : year = 1990;
}

bool Date::setDefaultDate() {
    setYear(1990); setMonth(1); setDay(1); 
    return true;
}

bool Date::setDate (int month, int day, int year) {}
bool Date::isValidDate(int m, int d, int y) {}

// Getters
int Date::getDaysOfMonth(int m) {
    
    /* Everything except February */
    if( m != 2) {
        int daysOfEachMonth[12] = { 31, 00, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        cout << endl << daysOfEachMonth[m - 1] << " days in " << m << endl;
        return daysOfEachMonth[m - 1];
    }
    
    /* Leap Year Conditions */
    else {
        int YR = getYear();
        cout << "Year = " << YR << endl;
        
        if (( YR % 100 ) % 400 == 0 ) {
            cout << "Leapyear\n";
            return 29;
        } 
        else if (( YR % 100 != 0) && ( YR % 4 == 0 )) { 
            cout << "Leapyear\n";
            return 29;
        } 
        else { 
            cout << "Not a Leapyear\n";
            return 28; 
        }
    }
}

void Date::display() {
    cout << this->month << '/' 
         << this->day   << '/' 
         << this->year  << endl;
}

int main() { 
    // Christmas 2001
    Date christmas(12, 25, 2001);
    christmas.display();
    
    // Date in Feb, not leap
    Date not_leap(2, 13, 2001);
    not_leap.display();
    
    // Date in Feb, valid leap
    Date good_leap(2, 29, 2000);
    good_leap.display();
    
    // Date in Feb, invalid leap
    Date bad_leap(2, 29, 2100);
    bad_leap.display();
    
    
    return 0; 
}