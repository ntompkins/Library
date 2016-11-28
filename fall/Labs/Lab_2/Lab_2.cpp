// Nathan Tompkins
// Lab 2 - 10/12/16
#include <iostream>
#include <iomanip>
using namespace std;

class Inventory {
	private:
		int itemNumber, 
			quantity;
		double cost;
		
	public:
		// Default
		Inventory() {
			setItemNumber(0);
			setQuantity(0);
			setCost(0.0);
		}
		// Initializing Constructor
		Inventory(int n, int q, double c) {
			setItemNumber(n);
			setQuantity(q);
			setCost(c);
		}
		// Accessors
		int getItemNumber() { return itemNumber; }
		int getQuantity() 	{ return quantity;	 }
		double getCost()	{ return cost;	  	 }
		
		// Mutators
		void setItemNumber (int n) 	{ itemNumber = n;}
		void setQuantity (int q) 	{ quantity = q; }
		void setCost (double c)		{ cost = c; }
		
		// Additional Functions
		double getTotalCost() { return quantity * cost;	}
};

int main() {
	Inventory item1;
	
	string err = "\nInvalid Value\n.";
	bool invalid = true;
	int usrItemNumber=0; 
	while (invalid) {
		cout << "\nEnter item number: ";
		cin >> usrItemNumber;
		if (usrItemNumber > 0) {
			invalid = false;
			item1.setItemNumber(usrItemNumber);
		} else {
			cout << err;
		}
	}
	invalid = true;
	int usrQuantity=0; 
	while (invalid) {
		cout << "\nEnter item quantity: ";
		cin >> usrQuantity;
		if (usrQuantity >= 0) {
			item1.setQuantity(usrQuantity);	
			invalid = false;
		} else {
			cout << err;
		}
	}
	invalid = true;
	double usrCost=0.0;
	while (invalid) {
		cout << "\nEnter item cost: $";
		cin >> usrCost;
		if (usrCost >= 0.0) {
			item1.setCost(usrCost); 
			invalid = false;
		} else {
			cout << err;
		}
	}
	cout << "Item #1\n"
		<< "Number: " << item1.getItemNumber() << endl
		<< "Quantity: " << item1.getQuantity() << endl
		<< "Cost: $" << fixed << setprecision(2) << item1.getCost()	<< endl
		<< "Total: $"<< fixed << setprecision(2) << item1.getTotalCost();	
	 
	cout << endl << endl;
	
	Inventory item2(usrItemNumber, usrQuantity, usrCost);
	cout << "Item #2\n"
		<< "Number: " << item2.getItemNumber() << endl
		<< "Quantity: " << item2.getQuantity() << endl
		<< "Cost: $" << fixed << setprecision(2) << item2.getCost()	<< endl
		<< "Total: $"<< fixed << setprecision(2) << item2.getTotalCost();	
return 0;
}
