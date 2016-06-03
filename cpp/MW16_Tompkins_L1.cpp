/*
 Author: Nathan Tompkins
 Course: COSC 1337 Summer 2016 MW16
 Instructor: Thayer
 Lab 1: Calculate restaurant bill and BMI calculator
*/
#include <iostream>
#include <iomanip> // This is included to set the precision of the output
using namespace std;

int main() {
	// Set precision for all numerical outputs to two decimal places
	cout << fixed;
	cout << setprecision(2);
	
		// Create loop for menu
		bool loop = true;
		while (loop)
		{
			// Program Menu
			cout << "Menu: a)mount of bill, calculate your b)mi, or q)uit: ";
			char response;
			cin >> response;
			
			// Convert response to lower case
			response = tolower(response);

			// Restaurant Bill
			if (response == 'a' )
			{
				cout << "\nBILL CALCULATOR\n";
				
				// get the cost of the food
				cout << "What was the cost of the food? $";
				double cost=0;
				cin >> cost;

				// get tip percentage
				cout << "What is your tip percentage? (5 = 5%) ";
				double tip_rate=0;
				cin >> tip_rate;

				// set tip_rate to percentage
				tip_rate = tip_rate / 100;

				// calculate subtotal
				double subtotal=0;
				subtotal = cost + (cost * tip_rate);
				
				// calculate tax
				double tax_rate = 0.0825;

				// calculate total bill
				double total = subtotal + (tax_rate * subtotal);
				
				cout << "\nYour Receipt\n"
					 << "Cost: 		$" << cost << "\n"
					 << "Tip: 		$" << tip_rate * cost << "\n"
					 <<	"Subtotal:	$" << subtotal << "\n"
					 << "+ Tax		$" << total - subtotal << "\n"
					 << "Total:		$" << total << "\n\n";
			}
			else if (response == 'b')
			{
				// BMI Calculator
				cout << "\nBMI CALCULATOR\n";
				
				// get weight
				cout << "What is your weight (in pounds)? ";
				// I changed weight from an int to a double
				// because it was causing looping issues if you
				// entered a decimal for your weight.
				double weight=0;
				cin >> weight;
				
				// Offer to get height in either inches or feet
				bool unit_loop = true;
				while (unit_loop)
				{
					cout << "Enter your height in i)nches or f)eet: ";
					char unit;
					cin >> unit;
					unit = tolower(unit);
					
					// Height in inches
					if (unit == 'i')
					{
						// Get height in inches
						cout << "What is your height in inches? ";
						double height=0; // changed from int to double
						cin >> height;
						
						// Calculate BMI
						double bmi=0;
						bmi = height * height;
						bmi = weight / bmi;
						bmi = bmi * 703.00;
				
						cout << "Your BMI is " << bmi << "\n\n";
						
						break;
					}
					else if (unit == 'f')
					{
						// Get height in feet
						cout << "What is your height in feet? ";
						double height=0; // changed from int to double
						cin >> height;
						
						// Convert from feet to inches
						height = height * 12;
						
						// Calculate BMI
						double bmi=0;
						bmi = height * height;
						bmi = weight / bmi;
						bmi = bmi * 703.00;
				
						cout << "Your BMI is " << bmi << "\n\n";
						
						break;
					}
					else
					{
						cout << "Invalid choice. Enter either i or f.\n";
					}
				}
			}
			else if (response == 'q')
			{
				cout << "\nGoodbye!";
				break;
			}
			else {
				cout << "\nInvalid choice. Enter either a, b, or q.\n";
			}
		}
	return 0;
}
/*	TEST OUTPUT

Menu: a)mount of bill, calculate your b)mi, or q)uit: a

BILL CALCULATOR
What was the cost of the food? $212.25
What is your tip percentage? (5 = 5%) 15

Your Receipt
Cost: 		$212.25
Tip: 		$31.84
Subtotal:	$244.09
+ Tax		$20.14
Total:		$264.22

Menu: a)mount of bill, calculate your b)mi, or q)uit: b

BMI CALCULATOR
What is your weight (in pounds)? 175.5
Enter your height in i)nches or f)eet: f
What is your height in feet? 5.5
Your BMI is 28.32

Menu: a)mount of bill, calculate your b)mi, or q)uit: x

Invalid choice. Enter either a, b, or q.
Menu: a)mount of bill, calculate your b)mi, or q)uit: q

Goodbye!

*/
