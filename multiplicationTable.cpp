#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
/*
MULTIPLICATION TABLE GENERATOR
- - - - - - - - - - - - - - -
This program gets table size, cell size, and an output file name,
and then it generates a file with that name and populates it
with a multiplication table based off of the previous information.

Script / Non OOP / Non Functional version
*/


int main()
{
  // Get table information
  cout << "Enter table size (default 12): ";
  int TABLE_SIZE = 12;
  cin >> TABLE_SIZE;
  cout << "Enter cell size (default 5): ";
  int CELL_SIZE = 5;
  cin >> CELL_SIZE;

  // Create numbers array
  int numbers[TABLE_SIZE];

  // Populate numbers array
  for(int i = 0; i < TABLE_SIZE; i++) {
    numbers[i] = i+1;
  }

  // Get file name
  cout << "Enter output file name: ";
  string tableName = "";
  cin >> tableName;

  // Create file with chosen name
  ofstream outfile(tableName.c_str());

  // Input table contents
  for(int j = 0; j < TABLE_SIZE+1; j++) {

    // Create file header on first loop
    if (j==0) {

      // Start of header
      outfile << setw(CELL_SIZE) << "x|";

      // Put array contents into header
      for(int k = 0; k < TABLE_SIZE; k++) {
        outfile << setw(CELL_SIZE) << numbers[k];
      }

      // Create end of header
      outfile << '\n' << string(CELL_SIZE*(TABLE_SIZE+1),'-') << endl;
    }

    // Create each row in the file
    else {

      // Create row head
      outfile << setw(CELL_SIZE-1) << numbers[j-1] << "|";

      // Input row contents
      for(int n = 1; n < TABLE_SIZE+1; n++) {
        outfile << setw(CELL_SIZE) << n*j;
      }
      // end the line and clear the buffer
      outfile << endl;
    }
  }
  return 0;
}
