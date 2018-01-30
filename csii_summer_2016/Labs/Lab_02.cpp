/*
 Author: Nathan Tompkins
 Course: COSC 1337 Summer 2016 MW16
 Instructor: Thayer
 Lab 2: Create diamond pattern based on user's input
*/

#include <iostream>
using namespace std;

int main() {
	// Make the program loop
	int size=1;
	while(size > 0)
	{
		// Get the size of the diamond
		cout << "Enter diamond size (0 to quit): ";
		cin >> size;
		
		// Create upper half
		for (int i = 1; i < size; i += 2)
		{
			for (int j = size; j >= i; j -= 2)
			{
				cout << " ";
			}
			for (int n = 1; n <= i; ++n)
			{
				cout << "*";
			}
			cout << endl;
		}
		// Create bottom half
		for (int i = 1; i <= size; i += 2)
		{
			for (int j = 1; j <= i; j += 2)
			{
				cout << " ";
			}
			for (int n = size; n >= i; --n)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
	
	// End of program
	cout << endl << "Goodbye!";
	return 0;
}
