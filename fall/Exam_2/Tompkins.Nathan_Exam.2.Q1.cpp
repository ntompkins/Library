// Nathan Tompkins  11/02/16
// Programming Fundamentals II
// Exam 2, Question 1

/*
Initialize a one-dimensional array with these values.  
The program should contain a loop that prompts the user 
to enter an account number.  An entry of a negative number 
should terminate the loop and end the program.  

If the number is not negative, utilize a simple linear search 
to locate the number entered by the user.  If the user 
enters a number that is in the array, the program should 
display a message saying the number is valid.  
If the user enters a number not in the array, the program 
should display a message indicating it is invalid.
*/
#include <iostream>
#include <string>

using namespace std;

string login(int, int, int []);

int main() {
    cout << "(Enter a negative number to end the program.)\n";
    int accounts[18] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
                        8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                        1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
    int usrAccount=0;
    while(usrAccount >= 0) {
        cout << "Enter an account number: ";
        cin >> usrAccount;
        cout << login(18, usrAccount, accounts);
    }
    return 0;
}
string login(int size, int usrAccount, int *accounts) {
        for(int i=0; i < size; i++) {
            if(usrAccount == accounts[i]) 
                return "Valid Account.\n";// Return valid statement
        }
        // Return invalid otherwise
        return "Invalid Account.\n";
}
