/*
Write a program that computes the tax 
and tip on a restaurant bill for a patron 
with a $44.50 meal charge. The tax should
be 6.75 percent of the meal cost. 
The tip should be 15 percent of the total 
after adding the tax. Display the meal 
cost, tax amount, tip amount, and total 
bill on the screen.
*/

// Nathan Tompkins | 9.7.16

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	cout << "Bill Calculator\n";
	
	// Set unchanging variables to constants
	const float mealCost = 44.50; 			// In dollars
	const float tax = 0.0675;				// 6.75% tax rate
	const float tip = 0.15 * mealCost;		// Find 15% of mealCost
	
	// Set all precision to 2 places
	cout << fixed << setprecision(2);
	
	// Output original cost of meal
	cout << "Meal cost:\t$" << mealCost << endl;
	
	// Calculate tax
	float totalBill = mealCost + (mealCost * tax);
	cout << "After tax:\t$" << totalBill << endl;
	
	// Show calculated tip
	cout << "Tip:\t\t$" << tip << endl;
	cout << "---------------------\n";
	
	// Calculate total
	totalBill = totalBill + (tip);
	cout << "Total:\t\t$" << totalBill << endl;

	return 0;
}

// Test Output
/*
Bill Calculator
Meal cost:      $44.50
After tax:      $47.50
Tip:            $6.68
---------------------
Total:          $54.18
*/
