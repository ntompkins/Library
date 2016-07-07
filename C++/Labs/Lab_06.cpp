/*
    Author: Nathan Tompkins
    Course: COSC 1337 Summer 2016 MW16
    Instructor: Paul Thayer
    Lab 5: Overloading functions
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Input functions
char input(string prompt="", string error_message=""); // for getting a letter
float input(float min=0.0, float max=0.0, string prompt="", string error_message=""); // for getting a number
void input(double &x, double &y, string prompt=""); // for getting a point (x, y)

// Distance functions
int dist(char a, char b); // return the distance between two letters (a-z)
float dist(float f1, float f2); // return the distance between two floating point numbers
double dist(double x1, double y1, double x2, double y2); // return distance between two points.

// Display functions
void display(string msg, char ch1, char ch2, int d); // display letter distance
void display(string msg, float f1, float f2, float d); // display number distance
void display(string msg, double x1, double y1, double x2, double y2, double d); // display point distance.


int main()
{
    cout << "Calculate the difference between\n";
    while (bool loopMenu=true)
    {
        // Menu
        cout << "l)etters, n)umbers, p)oints, or q)uit: ";
        
        char choice=' ';
        cin >> choice;
        
        // to lower case
        choice=tolower(choice);
        
        char firstLetter=' ', secondLetter=' ';
        int intDistance=0;
        float firstNumber=0, secondNumber=0, floatDistance=0;
        
        switch (choice) {
            case 'l':
                firstLetter = input("Enter a letter: ", "Error, please enter a letter.");
                secondLetter = input("Enter a letter: ", "Error, please enter a letter.");
                // Call distance function
                intDistance = dist((char)firstLetter, (char)secondLetter);
                //display("The distance between those letters is", firstLetter, secondLetter, intDistance);
                break;
            
            case 'n':
                firstNumber = input(-1000, 1000, "Enter a number between ", "Error, please enter a number within the valid range.\n");
                secondNumber = input(-1000, 1000, "Enter a number between ", "Error, please enter a number within the valid range.\n");
                floatDistance = dist(firstNumber, secondNumber);
                display("The distance between those numbers is ", (float)firstNumber, (float)secondNumber, floatDistance);
                break;
                
            case 'p':
                cout << "calc points." << endl;
                break;
            
            case 'q':
                cout << "\nGoodbye!\n";
                return 0;
   
            default:
                cout << "Error, invalid choice.\n\n";
                    
        }
    }
    return 0;
}

// letter getter 
char input(string prompt, string error_message) 
{
    while (bool loopMenu = true)
    {
        cout << prompt;
        char letter = ' ';
        cin >> letter;
        letter = tolower(letter);
        
        if (letter >= 'a' && letter <= 'z')
            return letter;
        else 
            cout << error_message;
    }
}

// Number getter 
float input(float min, float max, string prompt, string error_message)
{

    while (bool loopMenu=true)
    {
      cout << prompt << min << " and " << max << ": ";
        float number=0;
        cin >> number;
        
        if (number >= min && number <= max)
            return number;
        else
            cout << error_message;
    }
}

// Number diff calc
float dist(float f1, float f2) {
    float d = abs(f1 - f2);
    return d;
}

// Number display
void display(string msg, float f1, float f2, float d)
{
    cout << msg << d << endl;
}
