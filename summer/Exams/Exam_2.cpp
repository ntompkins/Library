/*
  Name: Nathan Tompkins
  COSC 1337 Summer 2016 MW16 or DL5
  Exam 2, Programming portion
*/
#include <iostream>
#include <iomanip>
using namespace std;

class CoinPurse
{
  private:
    int quarters=0, dimes=0, nickels=0, pennies=0;
  
  public:
  //  Step 1) Write two CoinPurse constructors:
  //    default: set all coin counts to zero
  //    2nd:     set all coin counts to initial values; use parameters for: penny, nickel, dime, quarter
  //    tip: you can combine both of these into one constructor
    bool set(int, int, int, int);
    
    CoinPurse(int q=0, int d=0, int n=0, int p=0) {
                         // Step 5) Implement set() which modifies the coin counts
        set(q, d, n, p); // Step 6) avoid redundant code, call set() in constructor(s)
    };
  // Step 3) Write total_value to return total value of coins in CoinPurse object
  int total_value();

  // Step 7) write show() method that outputs the number of each coin in the purse
  //  in one string, like this: "q=4 d=3 n=2 p=1" (don't << endl;)
  void show();

  // Step 9) write modify() method to modify coin counts using a positive (increment),
  // negative (decrement) or zero (keep the same) value.
  bool modify(int, int, int, int);
 
  bool setCents(int); // Extra credit
  
};

int CoinPurse::total_value() {
    return ((quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies));    
}

bool CoinPurse::set(int q, int d, int n, int p) {
    // Make sure all values are positive,
    // otherwise none are updated and default to 0
    if (q >= 0 && d >= 0 && n >= 0 && p >= 0) {
        // Update all values
        quarters= q;
        dimes   = d;
        nickels = n;
        pennies = p;
        return true;
    } else {
        return false;
    }
}

void CoinPurse::show() {
    cout << "(Q=" << quarters << " D=" << dimes << " N=" << nickels << " P=" << pennies<<")"; // Test constructor
}

bool CoinPurse::modify(int newQ, int newD, int newN, int newP) {
    // if changing the value of any coin becomes less than zero return false
    if ((quarters+newQ < 0)  || 
        (dimes+newD < 0)     ||
        (nickels+newN < 0)   || 
        (pennies+newP < 0))
            return false;
    else {
        quarters += newQ;
        dimes    += newD;
        nickels  += newN;
        pennies  += newP;
        return true; 
    }
}

bool CoinPurse::setCents(int cents) {
    if (cents <= 0) {
        return false;
    } 
    else {
        int numberToAdd=0;
        // Quarters
        numberToAdd = cents / 25;           // 1) Run division operation
        modify(numberToAdd,0,0,0);          // 2) Update value of coin to be added
        cents-=(numberToAdd * 25);          // 3) Subtract value of coins from cents
        // Dimes
        numberToAdd = cents / 10;
        modify(0,numberToAdd,0,0);
        cents-=(numberToAdd * 10);
        // Nickels
        numberToAdd = cents / 5;
        modify(0,0,numberToAdd,0);
        cents-=(numberToAdd*5);
        // Pennies
        numberToAdd = cents;
        modify(0,0,0,numberToAdd);
    }
}

int main() {
  cout << "COSC 1337 Exam 2 CoinPurse" << endl;

  // Step 2) declare CoinPurse object called purse1;
  // initialize with: 4 quarters, 3 dimes, 2 nickels, 1 penny
    CoinPurse purse1(4, 3, 2, 1);
  // Step 4) Call the total_value method on purse1; display the result formatted as: $x.xx
    cout << fixed << setprecision(2); 
    cout << "$" << purse1.total_value() / 100.00;
    
    cout << endl;
    purse1.show();
    
  // Step 8) Call set to change values in purse1 to: 8 quarters, 7 dimes, 6 nickels, 5 pennies.
  //         Call show to display the contents of purse1
    cout << endl;
    purse1.set(8, 7, 6, 5);
    purse1.show();
  
    cout << endl;
    
    // Step 9
    // cout<<"\nModify with bad values:  ";
    purse1.modify(-9, -7, 20, 60);
    purse1.show();  // No change
    
    cout << endl;
    
    // cout<<"\nModify with good values: ";
    purse1.modify(1, -2, -6, 30);
    purse1.show();  // Value change
    
    cout << endl;
  // Step 10) write menu driven loop that allows the user to add or remove coins from purse1.
    // Menu modifies values, does not set them
    bool loopMenu=true;
    while (loopMenu) {
        cout << fixed << setprecision(2); 
        cout << "$" << purse1.total_value() / 100.00 << " ";
        purse1.show(); 
        cout << " Modify q)uarters, d)imes, n)ickels, p)ennies, c)ents, or s)top: ";
        
        char choice=' ';
        cin >> choice;
        int newValue=0;
        string prompt="Add or subtract how many coins: ";
        switch (choice) {
            case('q'):
                cout << prompt;
                cin >> newValue;
                purse1.modify(newValue,0,0,0);
                break;
            case('d'):
                cout << prompt;
                cin >> newValue;
                purse1.modify(0,newValue,0,0);
                break;
            case('n'):
                cout << prompt;
                cin >> newValue;
                purse1.modify(0,0,newValue,0);
                break;
            case('p'):
                cout << prompt;
                cin >> newValue;
                purse1.modify(0,0,0,newValue);
                break;
            case('c'):          // Extra Credit
                cout << "Enter value: ";
                cin >> newValue;
                purse1.setCents(newValue);
                break;
            case('s'):
                loopMenu=false;
                break;
            default: 
                cout << "\nError, please try again.\n";
        }
    }
  // Step 12 EXTRA CREDIT) add option that allows the user to add a specific amount of cents
  
  cout<<endl<<"Goodbye!"<<endl; // this should appear as the last line of your output
  return EXIT_SUCCESS; // Use return 0 if EXIT_SUCCESS is undefined
}

/*  Step 11) Paste test output here (do this after step 12 if doing extra credit)
COSC 1337 Exam 2 CoinPurse
$1.41
(Q=4 D=3 N=2 P=1)
(Q=8 D=7 N=6 P=5)
(Q=8 D=7 N=6 P=5)
(Q=9 D=5 N=0 P=35)
$3.10 (Q=9 D=5 N=0 P=35) Modify q)uarters, d)imes, n)ickels, p)ennies, c)ents, or s)top: c
Enter value: 567
$8.77 (Q=31 D=6 N=1 P=37) Modify q)uarters, d)imes, n)ickels, p)ennies, c)ents, or s)top: -9

Error, please try again.
$8.77 (Q=31 D=6 N=1 P=37) Modify q)uarters, d)imes, n)ickels, p)ennies, c)ents, or s)top: 
Error, please try again.
$8.77 (Q=31 D=6 N=1 P=37) Modify q)uarters, d)imes, n)ickels, p)ennies, c)ents, or s)top: n
Add or subtract how many coins: -99
$8.77 (Q=31 D=6 N=1 P=37) Modify q)uarters, d)imes, n)ickels, p)ennies, c)ents, or s)top: q -99
Add or subtract how many coins: $8.77 (Q=31 D=6 N=1 P=37) Modify q)uarters, d)imes, n)ickels, p)ennies, c)ents, or s)top: q -31
Add or subtract how many coins: $1.02 (Q=0 D=6 N=1 P=37) Modify q)uarters, d)imes, n)ickels, p)ennies, c)ents, or s)top: s

Goodbye!
*/
