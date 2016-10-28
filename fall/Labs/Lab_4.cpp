//  Nathan Tompkins
//  Lab 4 - 10/27/2016
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double median(int *p, int size);
void showArray(int *array, int size);

int main() {
  // Create 2 arrays, and ints to hold their size
  int even_array[6]   = {1,2,3,4,5,6},
      odd_array[5]    = {1,2,3,4,5},
      sizeOfEvenArray = 6,
      sizeOfOddArray  = 5;
  
  // Odd Array
  cout << "For array: "; 
  showArray(odd_array, sizeOfOddArray); 
  cout << ", the median is " << median(odd_array,  sizeOfOddArray) << endl;
  
  
  // Even Array
  cout << "For array: ";
  showArray(even_array, sizeOfEvenArray);
  cout << ", the median is " << median(even_array, sizeOfEvenArray) << endl;
  
  return 0;
}

double median(int *p, int size) {
  // VERBOSE METHOD
  if (size % 2 == 0) {
    return (*(p + size / 2) + *(p + (size / 2 - 1))) / 2.0;
  } else {
    int ceiling = ceil(size / 2);
    return *(p + ceiling);
  }
  
  // CONCISE METHOD
  // Set ceiling for odd median
  // int ceiling = ceil(size/2);
  // If array is even return even median, otherwise return odd median
  // return size % 2 == 0 ? (*(p + size / 2) + *(p + (size / 2 - 1))) / 2.0 : *(p + ceiling);
}

void showArray(int *array, int size) {
  cout << "{" << array[0];
  for(int i=1; i < size; i++) {
    cout << ", " << (array[i]);
  }
  cout << "}";
}
