#include <string>
#include "date.hpp"

using namespace std;

const int DEF_MONTH = 1, DEF_DAY = 1, DEF_YEAR = 1990;

/* Set Date*/
bool Date::setDate(int m, int d, int y) {
    bool result = false;
    if (Date::isValidDate(m, d, y)) {
        /* Swap these to setX functions */
        Date::setYear(y); Date::setMonth(m); Date::setDay(d);
        result = true;
    }
    return result;
}

/* Default Date */
void Date::setDefaultDate() {
    setYear (DEF_YEAR);
    setMonth(DEF_MONTH);
    setDay  (DEF_DAY);
}

/* Setters */
bool Date::setMonth(int m) {
    bool result = false;
    if( 0 < m && m < 13) {
        result = true;
        month  = m;
    }
    return result;
}
bool Date::setDay  (int d) {
    bool result = false;
    if( 0 < d && d <= Date::daysInMonth(Date::getMonth())) {
        result = true;
        day    = d;
    }
    return result;
}
bool Date::setYear (int y) {
    bool result = false;
    if( 0 < y ) {
        result = true;
        year   = y;
    }
    return result;
}

/* Date Validation */
bool Date::isValidDate(int m, int d, int y) {
    const int daysInMonth[] 
        = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    bool result = false;
    if (0 < m && m < 13) {
        if (y > 0) {
            int maxDay = daysInMonth[m - 1];
            if (m == 2 && isLeapYear(y)) maxDay++;
            if (0 < d && d < maxDay)
                result = true;
        }
    }
    return result;
}


/* Value Checkers */
bool Date::isDefaultDate() {
    return (
            month == DEF_MONTH &&
            year  == DEF_YEAR  &&
            day   == DEF_DAY   &&
            ) ? true : false;
}

