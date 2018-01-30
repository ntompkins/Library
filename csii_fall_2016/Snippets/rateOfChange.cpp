// Nathan Tompkins
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Prototypes
bool loop();
double getInput(string,string);
double calculate(double,double,double);
void showTime(double);
double distanceOf(double, double);

int main() {
  cout << "Intersecting Rates of Change Calculator\n";
  
  // Loop for constant input
  while(loop()) {
    
     // Get total distance
    const double totalDistance = 
      getInput("Enter the total distance, in miles, between the cars: ",
        "Error: please enter a distance, greater than 0, in digits.\n");
        
    // Get first car's speed
    const double rateOfA = 
      getInput("Enter the speed in MPH of the first car: ", 
        "Error: please enter a speed, greater than 0, in digits.\n");
        
    // Get second car's speed
    const double rateOfB =
      getInput("Enter the speed in MPH of the second car: ",
        "Error: please enter a speed, greater than 0, in digits.\n");
   
    // Get first time
    const double totalTime = calculate(rateOfA,rateOfB,totalDistance);
    showTime(totalTime);
    
    cout << "Car 1 traveled " << distanceOf(totalTime, rateOfA) << " miles.\n";
    cout << "Car 2 traveled " << distanceOf(totalTime, rateOfB) << " miles.\n";
  }
  return 0;
}

// Program to verify user wants to continue or quit
bool loop() {
  bool not_quit = true;
  while(not_quit) {
    cout << "c)alculate both rates, or q)uit: ";
    char choice = ' ';
    cin >> choice;
    if((!cin)) {
      cout << "\nError, enter either \'c\' or \'q\'.\n";
      cin.clear(); // reset failbit
      cin.ignore(900, '\n'); //skip bad input
    }
    switch(choice) {
      case 'c':
        cout << "Calculate!\n";
        return true;
        break;
      case 'q':
        cout << "Goodbye!\n";
        not_quit = false;
        break;
      default: 
        cout << endl;
    }
  }
  return false;
}

// General purpose double input func with two string outputs
double getInput (string prompt="", string error="") {
  bool valid = true;
  while(valid) {
    cout << prompt;
    double reply=0.0;
    cin >> reply;
    
    if ((!cin) || (reply < 0)) {
      cout << error;
      cin.clear(); // reset failbit
      cin.ignore(900, '\n'); //skip bad input
    }
    else return reply;
  }
}

// calculate solution
double calculate(double rateOfA, double rateOfB, double totalDistance) {  // pass in both rates, and total distance
  double answer = totalDistance/(rateOfA+rateOfB); 
  return answer;
}

double distanceOf(double totalTime, double rate) {
  double answer = rate * totalTime; 
  return answer;
}

void showTime(double t) {    // Pass in some value of hours.
  if (t == 1) {
      cout << "Total time = 1 hour.\n";
  }
  else if (t < 1) {
      double minutes = t / 60;
      cout << "Total time = " << minutes << " minutes.\n";
  } 
  else if (t > 24) {
      double days = t / 24;
      cout << "Total time = " << days << " days.\n";
  }
  else {
      cout << "Total time = " << t << " hours.\n";
  }
  
}
