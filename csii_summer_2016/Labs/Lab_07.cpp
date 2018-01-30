/*
 Author: Nathan Tompkins
 Course: COSC 1337 Summer 2016 MW16
 Instructor: Paul Thayer
 Lab 7: Inventory class
*/
/* Inventory.txt content

100 5   7.99    Candles 
101 5   3.95    Soap    
102 4   8.00    Stationery  
103 10  1.50    Loofas  
104 2   .25     Bottle-openers  

*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Define class
class Inventory
{
  private:          
    // Private variables
    int itemNumber=0;
    int quantity=0;
    double cost=0.0;
    string name="";
  
  public:
    // Prototype Setters
    void setItemNumber(int n);
    void setQuantity(int q); 
    void setCost(double c);
    void setName(string nm);
    void display();
    
    // Constructors
    Inventory(int n, int q, double c, string nm)
    {                                   
        setItemNumber(n);
        setQuantity(q);
        setCost(c);
        setName(nm);
        getTotalCost();
    }   
    
    Inventory()  
    {
        itemNumber=0;
        quantity=0;
        cost=0.0;
        name="";
        
        getItemNumber();
        getQuantity();
        getCost();
        
        getTotalCost();
    }
    
    // Getters
    int getItemNumber() const { 
        return itemNumber;
    }
    
    int getQuantity() const { 
        return quantity;
    }
    
    double getCost() const { 
        return cost;
    }
    string getName() const {
        return name;
    }
    
    double getTotalCost() const { 
        return quantity * cost;    
    }
};

// Setters definitions
void Inventory::setItemNumber(int n) 
{
    if(n >= 0)
        itemNumber = n;
    else
        return; // default value
}

void Inventory::setCost(double c)
{
    if(c >= 0)
        cost = c;
    else
        return; // default value
}

void Inventory::setQuantity(int q)
{
    if(q >= 0 && q <= 5)
        quantity = q;
    else
        return; // default value
}

void Inventory::setName(string nm) 
{
    if(nm != "")
        name = nm;
    else
        return;
}

// display function to print results
void Inventory::display() {
    cout << name << endl;
    cout << "Item #" << itemNumber << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Cost $" << fixed << setprecision(2) << cost << endl;
    cout << "Total Value: $" << fixed << setprecision(2) << quantity * cost << endl << endl;
}

// int Inventory::openFile(string file_to_open) {
//     // Open file to read
//     const string inFileName=file_to_open;
//     ifstream inFile(inFileName);
    
//     if (inFile)
//     {
//         cout << file_to_open << " was successfully opened.\n\n";
        
//         while(!inFile.eof())     // Loop until eof reached
//         {
//             Inventory nextItem;
//             inFile >> n >> q >> c >> nm; 
            
//             if(inFile.eof())        
//                 break;
//         }
//     }    
//     else {
//         return 1;
//     }
// }

int main()
{
    // Call constructor for Inventory class
    // item ( itemnumber, quantity, cost, name )
    cout << "Number of products to enter: ";
    int itemsLeft=0;
    cin >> itemsLeft;
    
    // Variable to hold all inventory value
    double totalValue = 0.0; 
    for (int itemCount=0; itemCount < itemsLeft; ++itemCount) 
    {
        Inventory customerItem;
        cout << "Enter item name: ";
        string customName = "";
        cin >> customName;
        customerItem.setName(customName);
        
        cout << "Enter item number: ";
        int customNumber=0;
        cin >> customNumber;
        customerItem.setItemNumber(customNumber);
        
        cout << "Enter item quantity (1-5): ";
        int customQuantity=0;
        cin >> customQuantity;
        customerItem.setQuantity(customQuantity);
        
        cout << "Enter item cost: $";
        double customCost=0.0;
        cin >> customCost;
        customerItem.setCost(customCost);
        
        customerItem.display();
    }
    
    
    Inventory item1(2315, 15, 5.95, "Soap");
    item1.display();
    
    item1.setCost(3.39);
    item1.display();
    
    Inventory item2(817, 25, 3.00, "Candles");
    item2.display();
    
    
    Inventory item3(0,0,0,"Cardstock");
    item3.display();
    item3.setItemNumber(312);
    item3.setCost(5.99);
    item3.setQuantity(30);
    item3.setName("New Cardstock"); 
    item3.display();
    
    // Call file opening function
    // openFile("catalog.txt");

    cout << "Goodbye.\n";
    return 0;
}
