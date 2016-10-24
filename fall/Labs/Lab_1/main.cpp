// Example program
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>
#include "coin.hpp"
#include "coin.cpp"

using namespace std;

bool menu() {
  while (bool invalid=true) {
    cout << "f)lip coins, or q)uit: ";
    char choice = ' ';
    cin >> choice;
    choice = tolower(choice);
    
    if (!cin) {
      cout << "\nInvalid choice. Enter either \'f\', or \'q\'.\n"; 
      cin.clear();
      cin.ignore(1000, '\n');
    } 
    switch(choice) {
      case 'f':
        return true;
        break;
      case 'q':
        return false;
        break;
      default:
        cout << "\nInvalid choice. Enter either \'f\', or \'q\'.\n"; 
    }
  }
}

int main()
{
  cout << "Coin Flipping Simulation\n";
  Coin coin;
  while (menu()) {
    cout << "Enter the number of flips: ";
    int flips=0;
    cin >> flips;
    cout << "\nFlipping coins...\n\n";
    
    for (int i=0; i < flips; ++i) {
      coin.tossCoin();
      cout << coin.getSideUp() << endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    // Print results
    cout  << "\nNumber of heads:\t"  << coin.getHeadsCount() << endl
          << "Number of tails:\t"    << coin.getTailsCount() << endl
          << "Total tosses:\t\t"       << coin.getTossCount() << endl << endl;
  }
  return 0;
}
