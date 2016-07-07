/*
Classes and Objects

---

Don't make brittle functions--anything
that limits the function to only one
use "breaks" the function.

Once you create your own structure,
the automatically generated structure
is removed.

A function is standalone procedure,
method or method function is nested
inside a class object.

struct makes contents public
class makes contents private

class f() {
	public:	// makes contents public
		x1;
	private: // makes contents private
		x2;
	public: // back to public
		get_x2() const {	// gets, but cannot access or change value
			return x2;
		}
}
---

Lab 6

input (string)
input (&x, &y)
start

*/

#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum directions_t { north, south, east, west };

// Use a structure to bundle a set of data that you will store things in
struct query_t {	// _t to show data type not variable
	// initialize variables to empty value
	// int value; bad bad bad
	int value=0;
	char char_option=' ';
	string prompt; // String is auto assigned no value
	
	query_t(string pname, int init_value, char option_letter) // 1. Exact same name as struct. 2. No return value at all in this function.
	{	// query_t Qheight("What is your height in inches? ", 60, 'h');	
		value=init_value;
		prompt=pname;
		char_option=option_letter;
		
		
	}
	
	// Overload constructor
	query_t(){	// No parameters
		int value=0;
		char char_option=' ';
		string prompt;
		
		value=100;
		char_option='X';
		prompt="Default prompt";
		
		// 
		query_t::value=0;
		query_t::char_option='Y';
		query_t::prompt="Default query prompt";
	}
};

void Qshow (query_t QtoShow)
{
	cout << QtoShow.value << "   ";
	cout << QtoShow.char_option << "   ";
	cout << QtoShow.prompt << "   ";
	cout << endl;
}

main() {
	cout << "Hello...\n";
	
	int year=2016;
	char option='y';
	string year_prompt="please enter the current year: ";
	
	directions_t to_santone=south;
	
	query_t Qyear1, Qyear2, Qyear3;	// Q shows query
	
	Qshow(Qyear1);
	
	// Change values
	Qyear1.value=2011;
	Qyear1.char_option='y';
	Qyear1.prompt=year_prompt;
	
	// cout << Qyear1.value << "   ";
	// cout << Qyear1.char_option << "   ";
	// cout << Qyear1.prompt << "   ";
	// cout << endl;
	
	Qshow(Qyear1);
	
	query_t Qheight("What is your height in inches? ", 60, 'h');
	Qshow(Qheight);
	
	cout << "\n...Goodbye!";
}

// Test Output
/*

*/
