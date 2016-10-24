#include <iostream>
#include <iomanip>
#include <string>
#include "box.hpp"
#include "box.cpp"

using namespace std;

int main(int argc, char** argv) {
  Box box1;
  box1.setLength(2);
  box1.setWidth(4);
  box1.setDepth(2);
  cout << box1.calcVolume() << endl;
  cout << box1.calcArea() << endl;
  
  Box box2(2,5,10);
  cout << box2.calcVolume() << endl;
  
  Box box3(2,1,0.5);
  cout << box3.calcVolume() << endl;
  return 0;
}