/*
 Author: Nathan Tompkins
 Course: COSC 1337 Summer 2016 MW16
 Instructor: Paul Thayer
 Lab 7: Inventory class
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Define class
class Inventory
{
  
  private:
    // Private variables
    int itemNumber;
    int quantity;
    double cost;
  
  public:
    // Prototype Setters
    void setItemNumber(int n);
    void setQuantity(int q);
    void setCost(double c);

    // Constructors
    Inventory()
    {
        itemNumber=0;
        quantity=0;
        cost=0.0;
    }
    
    Inventory(int n, int q, double c)   // Accepts an item's number, quantity, and cost as arguments.
    {                                   // Calls functions to copy these values into the appropriate
                                        // member variables. Then calls the setTotalCost() function.
        itemNumber=n;
        quantity=q;
        cost=c;
        
        setItemNumber(n);
        setQuantity(q);
        setCost(c);
        
        getTotalCost();
    }
    
    // Getters
    int getItemNumber() {
        return itemNumber;
    }
    
    int getQuantity() {
        return quantity;
    }
    
    double getCost() {
        return cost;
    }
    
    double getTotalCost() {
        cout << "Your total is $" << fixed << setprecision(2) << quantity * cost << endl << endl;
        return quantity * cost;
    }
};

// Setters definitions
// item number
void Inventory::setItemNumber(int n)
{
    cout << "Enter an item number: ";
    cin >> n;
    
    if(n >= 0)
        itemNumber = n;
    else
        cout << "Error, invalid item number provided.\n";
}

// cost
void Inventory::setCost(double c)
{
    cout << "Enter the item's cost: $";
    cin >> c;
    
    if(c >= 0)
        cost = c;
    else
        cout << "Error, invalid cost provided.\n";
}

// quantity
void Inventory::setQuantity(int q)
{
    cout << "Enter the quantity: ";
    cin >> q;
    
    if(q >= 0)
        quantity = q;
    else
        cout << "Error, invalid quantity provided.\n";
}

int main()
{
    // Call constructor for Inventory class on 2 objects
    Inventory item1(0,0,0.0), item2(0,0,0.0);
    
    cout << "Goodbye.\n";
    return 0;
}
