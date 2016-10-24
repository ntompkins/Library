/*
 Author: Nathan Tompkins
 Course: COSC 1337 Summer 2016 MW16
 Instructor: Thayer
 Lab 3: Math tutor program
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

main() {
	
	// Welcome menu
	cout << "MATH TUTOR\n";
	cout << "Enter a negative number to quit.\n";
	
	// Create random seed based on time
	srand(time(NULL));
	
	// Loop through while value of answer is >= 0
	int answer=0;
	while (answer >= 0) {
		// Create two values between 0 and 100
		int denom = (rand() % 100);
		int numer = (rand() % 100);
		
		// Create selection index
		int operandIndex [4] = { 1, 2, 3, 4 };
	
		// Randomly select the operator
		int opSelect = operandIndex[rand() % 4];
		
		char operand = 'n'; // Printable operand
		int solution = 0;	// init solution
		

		// Create variables to count the number of successful questions generated
		int numAdd=0, numSub=0, numMul=0, numDiv=0;
		
		// Find solution based on selected operand
		
		if (opSelect == 1) 						// Addition
		{
			operand = '+';					// Create printable operand
			solution = numer + denom;		// Find real solution
			
			if (solution > 100) { 
				continue; 
			}								// Limit the product to < 100
			else {
				++numAdd; 
			}								// Or increase number of questions asked
		}
		else if (opSelect == 2)	 				// Subtraction
		{
			operand = '-';
			solution = numer - denom;
			if (solution <= 0) continue;
			else ++numSub;
		}
		else if (opSelect == 3) 				// Multiplication
		{
			operand = '*';
			solution = numer * denom;
			if (solution > 100) continue;
			else ++numMul;
		}
		else {									// Division
		
			operand = '/';
			solution = numer / denom;
			if (solution <= 0) continue;
			else ++numDiv;
		}

		// Print out the problem for the student
		cout << endl << numer << " " << operand << " " << denom << " = ";
		
		// Get their answer (sentinel to quit)
		cin >> answer;
		
		
	// Create variables to hold answers
//		int add_c=0, sub_c=0, mul_c=0, div_c=0, 
//			add_i=0, sub_i=0, mul_i=0, div_i=0;
		
	// Compare and log answers
		// Correct answers results
		if (answer == solution)	{
			cout << "Correct, the answer was " << solution << endl;
			
//			// Log correct answers
//			if (opSelect == 1) {
//				++add_c; }
//			else if (opSelect == 2) {
//				++sub_c; }
//			else if (opSelect == 3) {
//				++mul_c; }
//			else {
//				++div_c; }
		} 
		// Incorrect answers results
		else {
			cout << "Incorrect, the answer was " << solution << endl;
//			
//			// Log incorrect answers
//			if (opSelect == 1) {
//				++add_i; }
//			else if (opSelect == 2) 
//				{++sub_i; }
//			else if (opSelect == 3) {
//				++mul_i; }
//			else {
//				++div_i; }
		}

	}
	
	/*		
		// This code is for grading the answers.
		// It does not work right now.

		// Print out results
		//cout << "RESULTS" << endl;
		
		// Addition results
		if (add_c > add_i) {
			cout << "You passed addition with a grade of " << add_c / numAdd << endl;
		} else {
			cout << "You failed addition with a grade of " << add_i / numAdd << endl;
		}
		
		// Subtraction results
		if (sub_c > sub_i) {
			cout << "You passed subtraction with a grade of " << sub_c / numSub << endl;
		} else {
			cout << "You failed subtraction with a grade of " << sub_i / numSub << endl;
		}

		// Multiplication results
		if (mul_c > mul_i) {
			cout << "You passed multiplication with a grade of " << mul_c / numMul << endl;
		} else {
			cout << "You failed multiplication with a grade of " << mul_i / numMul << endl;
		}
		
		// Division results
		if (div_c > div_i) {
			cout << "You passed division with a grade of " << div_c / numDiv << endl;
		} else {
			cout << "You failed division with a grade of " << div_i / numDiv << endl;
		}
	}
	
*/	
	// End of program
	cout << "\nGoodbye!";
	return 0;
}

/* 
EXAMPLE OUTPUT

MATH TUTOR
Enter a negative number to quit.

82 - 65 = 5
Incorrect, the answer was 17

3 + 33 = 36
Correct, the answer was 36

82 - 45 = 6000
Incorrect, the answer was 37

85 + 1 = 96
Incorrect, the answer was 86

75 / 27 = 2
Correct, the answer was 2

93 - 38 = 60
Incorrect, the answer was 55

99 / 40 = -10
Incorrect, the answer was 2

Goodbye!
--------------------------------
*/



