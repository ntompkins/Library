// Here is some sample code to look at the behavior of defaults and overloading.

#include <iostream>
#include <iomanip>              // for set precision
using namespace std;

// ====================================
// Here are four different functions with four different names

int intshort(int i1, short s1) {
  cout << "we are in intshort. with int = " << i1 << " and short = " << s1 << '\n';
  return 1;
}

int intint(int i1, int i2) {
  cout << "we are in intint. with int = " << i1 << " and int = " << i2 << '\n';
  return 2;
}

int shortint(short s1, int i1) {
  cout << "we are in shortint. with short = " << s1 << " and int = " << i1 << '\n';
  return 3;
}

int shortshort(short s1, short s2) {
  cout << "we are in shortshort. with short = " << s1 << " and short = " << s2 << '\n';
  return 4;
}

// ======================================
// Here are four different functions with the same name, but a different signature (parameter list)

int samename(int i1, short s1) {
  cout << "we are in samename. with int = " << i1 << " and short = " << s1 << '\n';
  return 1;
}

int samename(int i1, int i2) {
  cout << "we are in samename. with int = " << i1 << " and int = " << i2 << '\n';
  return 2;
}

int samename(short s1, int i1) {
  cout << "we are in samename. with short = " << s1 << " and int = " << i1 << '\n';
  return 3;
}

int samename(short s1, short s2) {
  cout << "we are in samename. with short = " << s1 << " and short = " << s2 << '\n';
  return 4;
}

int getDefault(int ival = 1111);

int main ()
{
  intshort(1, 2);
  intint(3, 4);
  shortint(5, 6);
  shortshort(7, 8);
  
  cout << endl;
  
  samename(1, 2);  // by default, this is integer type
  samename(3, 4);
  samename(5, 6);
  samename(7, 8);
  
  // samename(9.0, 10.0); // what does this do?? Why is it commented out?
  // if there were a samename() for both float, float; and double, double, which will be called?

  cout << endl;
  
  // note there are three different ways to cast
  samename((short)1, 2);  // use casting to change the type
  samename(3, (short) 4);
  samename(static_cast<short> (5), static_cast<short> (6));
  samename(int(7), int(8));  // no need to cast here, but it doesn't hurt

  cout << endl;

  // for something completely different, look at defaults.
  // You can specify the default values on EITHER the function prototype, OR the function header, but NOT BOTH!
  cout << "Here is my value from getDefault: " << getDefault() << endl;
  cout << "Here is my value from getDefault: " << getDefault(2222) << endl;
  cout << "Here is my value from getDefault: " << getDefault(3333) << endl;
  
  system("pause");
   
  return 0;
}

int getDefault(int ival)   // Note: the default parameter value is NOT repeated here.
{
  return ival;
}