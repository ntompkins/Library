#ifndef DATE_H
#define DATE_H
#include <string>

using namespace std;

enum DateFormat { SHORT_DATE, LONG_DATE };

class Date {
    int year, month, day;
    void setDefaultDate();
    
    public:
        Date() { setDefaultDate(); }
        Date(int m, int d, int y) {
            if ( isValidDate(m, d, y) ) { month = m; day = d; year = y; }
            else setDefaultDate();
        }
        
        int getMonth()  { return month; }
        int getDay()    { return day;   }
        int getYear()   { return year;  }
    
        bool setMonth   (int m);
        bool setDay     (int d);
        bool setYear    (int y);
    
        bool isDefaultDate();
        bool setDate      (int m, int d, int y);
 static bool isValidDate  (int m, int d, int y);
 static bool isLeapYear   (int m, int d, int y);
        string toString   (DateFormat df = SHORT_DATE);
};

static bool isValidDate   (int m, int d, int y);
static bool isLeapYear    (int m, int d, int y);

#endif
