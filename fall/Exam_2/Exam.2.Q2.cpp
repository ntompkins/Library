// Nathan Tompkins  11/02/16
// Programming Fundamentals II
// Exam 2, Question 2

/*
The arrays source and target are integer arrays that hold the same number of elements.  
Write a function that copies the values in array source to array target.  
The function prototype is

void CopyArray (int *source, int *target, int size);

where source and target are pointers to arrays of integers and 
size is the number of elements in each array.
*/
#include <iostream>
#include <string>

using namespace std;

void copyArray(int *source, int *target, int size);
void showArray(int *array, int size);

int main() {
  // Declare 2 arrays
  int source[9] = {1,2,3,4,5,6,7,8,9},
      target[9];
      
  // Show the contents of source array
  cout << "Source array = ";
  showArray(source, 9);
  cout << endl;
  
  // Copy the contents over to target
  copyArray(source, target, 9);
  
  // Show the contents of target
  cout << "Target array = ";
  showArray(target, 9);
  
  return 0;
}

void copyArray(int *source, int *target, int size) {
  for(int i=0; i < size; i++) {
    target[i] = source[i];
  }
}

void showArray(int *array, int size) {
  cout << "{" << array[0];
  for(int i=1; i < size; i++) {
    cout << ", " << (array[i]);
  }
  cout << "}";
}