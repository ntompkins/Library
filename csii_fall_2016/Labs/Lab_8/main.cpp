#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include "Date.hpp"

using namespace std;

int main() {
	Date date(10, 12, 1998);
	cout << date.Date::toString();
	
	return 0;
}

